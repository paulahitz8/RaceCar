#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "glut/glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	//a wall
	wall = new Cube(10, 10, 10);
	wall->SetPos(10, 5, -10);
	wall->color = Red;
	wallA = App->physics->AddBody(*wall, 0);

	//ground
	ground = new Cube(100, 1, 100);
	ground->SetPos(0, 0, -1);
	ground->color = Green;
	groundA = App->physics->AddBody(*ground, 0);

	CreateTrack({ 0,0,10 }, 1000, Red, 0.0f, 20);

	startMusic = true;
	gameMusic = true;
	finishMusic = true;
	start = false;
	timerFx = 0;
	timerMusic = 0;

	musicFx = App->audio->LoadFx("Assets/Audio/Music/game_music.ogg");
	victoryFx = App->audio->LoadFx("Assets/Audio/Music/victory.ogg");
	loseFx = App->audio->LoadFx("");
	clapFx = App->audio->LoadFx("Assets/Audio/Fx/clap.ogg");

	finishLineFx = App->audio->LoadFx("Assets/Fx/finish.wav");
	startFx = App->audio->LoadFx("Assets/Audio/Music/start.wav");
	oneFx = App->audio->LoadFx("Assets/Audio/Fx/one.wav");
	twoFx = App->audio->LoadFx("Assets/Audio/Fx/two.wav");
	threeFx = App->audio->LoadFx("Assets/Audio/Fx/three.wav");
	goFx = App->audio->LoadFx("Assets/Audio/Fx/go.wav");

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.color = White;
	p.Render();

	if (!start)
	{
		if (startMusic)
		{
			Mix_Volume(-1, 10);
			App->audio->PlayFx(startFx, 0);
			startMusic = false;
		}
		if (timerFx > 200 && timerFx < 202)
		{
			App->audio->PlayFx(oneFx, 0);
		}
		if (timerFx > 280 && timerFx < 282)
		{
			App->audio->PlayFx(twoFx, 0);
		}
		if (timerFx > 360 && timerFx < 362)
		{
			App->audio->PlayFx(threeFx, 0);
		}
		if (timerFx > 440 && timerFx < 442)
		{
			App->audio->PlayFx(goFx, 0);
			timerFx = 0;
		}
		timerFx++;
	}

	if (start && !App->player->isWon)
	{
		if (gameMusic)
		{
			App->audio->PlayFx(musicFx, 0);
			gameMusic = false;
		}
	}
	
	if (App->player->time > 8)
	{
		start = true;
	}

	if (App->player->isLose)
	{
		App->audio->PlayMusic("Assets/Music/lose_music.ogg", 0.0f);

	}
	if (App->player->isWon)
	{
		if(timerMusic < 2) App->audio->StopFx(-1);
		if (finishMusic)
		{
			if (timerMusic > 10)
			{
				App->audio->PlayFx(clapFx, 0);
				App->audio->PlayFx(victoryFx, 0);
				finishMusic = false;
			}
		}
		timerMusic++;

	}

	wall->Render();
	//ground->Render();
	for (int i = 0; i < trackArray.cubeArray.Count(); i++)
	{
		trackArray.cubeArray[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

//void CreateTrack(vec3 trackPos, float trackLength, float trackAngle, float trackDistance, Color trackColor);
//void CreateCurve(vec3 curvePos, int curveLength, float curveAngle, Color curveColor);
//void CreateDoors(vec3 doorPos, float doorAngle, Color doorColor);
//void CreateRamp(vec3 rampPos, float rampLength, float rampHeight, float rampAngle);

void ModuleSceneIntro::CreateTrack(vec3 trackPos, float trackLength, Color trackColor, float trackAngle, float trackDist)
{
	vec3 size = {};

	Cube shape;
	PhysBody3D* shapeCol;

	if (trackAngle == 0.0f)
	{
		size = { 1.0f, 6, trackLength };

		shape.size = size;
		shape.color = trackColor;

		shape.SetPos(trackPos.x + trackDist, trackPos.y + 3, trackPos.z + 3);
		trackArray.cubeArray.PushBack(shape);
		trackArray.physArray.PushBack(App->physics->AddBody(shape, 0.0f));

		shape.SetPos(trackPos.x - trackDist, trackPos.y + 3, trackPos.z + 3);
		trackArray.cubeArray.PushBack(shape);
		trackArray.physArray.PushBack(App->physics->AddBody(shape, 0.0f));
	}

	else if (trackAngle == 1.0f)
	{
		size = { trackLength, 6, 1.0f };

		shape.size = size;
		shape.color = trackColor;

		shape.SetPos(trackPos.x + 3, trackPos.y + 3, trackPos.z + trackDist);
		trackArray.cubeArray.PushBack(shape);
		trackArray.physArray.PushBack(App->physics->AddBody(shape, 0.0f));

		shape.SetPos(trackPos.x + 3, trackPos.y + 3, trackPos.z - trackDist);
		trackArray.cubeArray.PushBack(shape);
		trackArray.physArray.PushBack(App->physics->AddBody(shape, 0.0f));
	}
}