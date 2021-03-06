#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "ModulePlayer.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"
#include "glut/glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	CreateTrack({ 0,20,10 }, 50, 0.0f, Purple, 12.0f);
	CreateRamp({ 0,21,45 }, 20, 8, 0.0f, Purple);
	CreateRamp({ 0,21,74 }, 20, -8, 0.0f, Purple);
	CreateTrack({ 0,20,99 }, 40, 0.0f, Purple, 12.0f);
	CreateCurve({ 0,20,120 }, 3, 0, 180, 50, Purple);
	CreateRamp({ -100,23,100 }, 41, -8, 0.0f, Purple);
	CreateCurve({ -200,26,82 }, 3, 180, 360, 50, Purple);
	CreateRamp({ -200,29,102 }, 40, 8, 0.0f, Purple);
	CreateCurve({ -150,24,182 }, 3, 90, 180, 50, Purple);
	CreateTrack({ -87,24,182 }, 130, 1.0f, Purple, 12.0f);
	CreateRamp({ 20,30,182 }, 90, -8, 1.0f, Purple);
	CreateRamp({ 120,46,182 }, 40, 90, 1.0f, Purple);
	CreateTrack({ 96,20,103 }, 164, 0.0f, Purple, 48.0f);
	CreateWall({ 120,23,103 }, 164, 90, Purple);
	CreateWall({ 72,23,103 }, 164, 90, Purple);
	CreateWall({ 96,23,185 }, 48, 0, Purple);
	CreateWall({ 113,23,21 }, 14, 0, Purple);
	CreateWall({ 83,23,21 }, 22, 0, Purple);

	CreateWall({ 100,23,160 }, 40, 0, Purple);
	CreateWall({ 92,23,150 }, 40, 0, Purple);

	CreateWall({ 112,23,140 }, 5, 0, Purple);
	CreateWall({ 110,23,137 }, 5, 90, Purple);
	CreateWall({ 113,23,135 }, 5, 0, Purple);
	CreateWall({ 115,23,138 }, 5, 90, Purple);

	CreateWall({ 92,23,140 }, 5, 0, Purple);
	CreateWall({ 90,23,137 }, 5, 90, Purple);
	CreateWall({ 93,23,135 }, 5, 0, Purple);
	CreateWall({ 95,23,138 }, 5, 90, Purple);

	CreateWall({ 102,23,130 }, 5, 0, Purple);
	CreateWall({ 100,23,127 }, 5, 90, Purple);
	CreateWall({ 103,23,125 }, 5, 0, Purple);
	CreateWall({ 105,23,128 }, 5, 90, Purple);

	CreateWall({ 97,23,120 }, 5, 0, Purple);
	CreateWall({ 95,23,117 }, 5, 90, Purple);
	CreateWall({ 98,23,115 }, 5, 0, Purple);
	CreateWall({ 100,23,118 }, 5, 90, Purple);

	CreateWall({ 77,23,145 }, 5, 0, Purple);
	CreateWall({ 75,23,142 }, 5, 90, Purple);
	CreateWall({ 78,23,140 }, 5, 0, Purple);
	CreateWall({ 80,23,143 }, 5, 90, Purple);

	CreateWall({ 77,23,125 }, 5, 0, Purple);
	CreateWall({ 75,23,122 }, 5, 90, Purple);
	CreateWall({ 78,23,120 }, 5, 0, Purple);
	CreateWall({ 80,23,123 }, 5, 90, Purple);

	CreateWall({ 87,23,130 }, 5, 0, Purple);
	CreateWall({ 85,23,127 }, 5, 90, Purple);
	CreateWall({ 88,23,125 }, 5, 0, Purple);
	CreateWall({ 90,23,128 }, 5, 90, Purple);

	CreateWall({ 107,23,116 }, 5, 0, Purple);
	CreateWall({ 105,23,113 }, 5, 90, Purple);
	CreateWall({ 108,23,111 }, 5, 0, Purple);
	CreateWall({ 110,23,114 }, 5, 90, Purple);

	CreateWall({ 116,23,50 }, 5, 0, Purple);
	CreateWall({ 114,23,47 }, 5, 90, Purple);
	CreateWall({ 117,23,45 }, 5, 0, Purple);
	CreateWall({ 119,23,48 }, 5, 90, Purple);

	CreateWall({ 107,23,65 }, 5, 0, Purple);
	CreateWall({ 105,23,62 }, 5, 90, Purple);
	CreateWall({ 108,23,60 }, 5, 0, Purple);
	CreateWall({ 110,23,63 }, 5, 90, Purple);

	CreateWall({ 102,23,45 }, 5, 0, Purple);
	CreateWall({ 100,23,42 }, 5, 90, Purple);
	CreateWall({ 103,23,40 }, 5, 0, Purple);
	CreateWall({ 105,23,43 }, 5, 90, Purple);

	CreateWall({ 92,23,60 }, 5, 0, Purple);
	CreateWall({ 90,23,57 }, 5, 90, Purple);
	CreateWall({ 93,23,55 }, 5, 0, Purple);
	CreateWall({ 95,23,58 }, 5, 90, Purple);

	CreateWall({ 82,23,60 }, 5, 0, Purple);
	CreateWall({ 80,23,57 }, 5, 90, Purple);
	CreateWall({ 83,23,55 }, 5, 0, Purple);
	CreateWall({ 85,23,58 }, 5, 90, Purple);

	CreateWall({ 112,23,40 }, 5, 0, Purple);
	CreateWall({ 110,23,37 }, 5, 90, Purple);
	CreateWall({ 113,23,35 }, 5, 0, Purple);
	CreateWall({ 115,23,38 }, 5, 90, Purple);

	CreateWall({ 92,23,40 }, 5, 0, Purple);
	CreateWall({ 90,23,37 }, 5, 90, Purple);
	CreateWall({ 93,23,35 }, 5, 0, Purple);
	CreateWall({ 95,23,38 }, 5, 90, Purple);

	CreateWall({ 87,23,50 }, 5, 0, Purple);
	CreateWall({ 85,23,47 }, 5, 90, Purple);
	CreateWall({ 88,23,45 }, 5, 0, Purple);
	CreateWall({ 90,23,48 }, 5, 90, Purple);

	CreateWall({ 87,23,30 }, 5, 0, Purple);
	CreateWall({ 85,23,27 }, 5, 90, Purple);
	CreateWall({ 88,23,25 }, 5, 0, Purple);
	CreateWall({ 90,23,28 }, 5, 90, Purple);

	CreateCurve({ 0,20,-10 }, 3, 180, 360, 50, Purple);
	CreateTrack({ 100,20,5 }, 35, 0.0f, Purple, 12.0f);

	check1.size = { 12, 12, 1 };
	check1p = App->physics->AddBody(check1, 0);
	check1p->SetPos(0, 21, 20);
	check1p->GetTransform(&check1.transform);
	check1p->SetAsSensor(true);
	check1p->collision_listeners.add(this);

	check1Box.size = { 15, 1, 1 };
	check1Box.color = DarkPurple;
	check1Box.SetPos(0, 27, 20);
	trackArray.cubeArray.PushBack(check1Box);
	trackArray.physArray.PushBack(App->physics->AddBody(check1Box, 0.0f));

	check1RStand.size = { 1, 7, 1 };
	check1RStand.color = Purple;
	check1RStand.SetPos(-5.5f, 23, 20);
	trackArray.cubeArray.PushBack(check1RStand);
	trackArray.physArray.PushBack(App->physics->AddBody(check1RStand, 0.0f));

	check1LStand.size = { 1, 7, 1 };
	check1LStand.color = Purple;
	check1LStand.SetPos(5.5f, 23, 20);
	trackArray.cubeArray.PushBack(check1LStand);
	trackArray.physArray.PushBack(App->physics->AddBody(check1LStand, 0.0f));

	check2.size = { 12, 12, 1 };
	check2p = App->physics->AddBody(check2, 0);
	check2p->SetPos(-100, 21, 120);
	check2p->GetTransform(&check2.transform);
	check2p->SetAsSensor(true);
	check2p->collision_listeners.add(this);

	check2Box.size = { 1, 1, 1 };
	check2Box.color = Gray;
	check2Box.SetPos(-94.5f, 24, 120);
	trackArray.cubeArray.PushBack(check2Box);
	trackArray.physArray.PushBack(App->physics->AddBody(check2Box, 0.0f));

	check2BoxSike.size = { 1.1f, 1.1f, 1.1f };
	check2BoxSike.color = DarkPurple;
	check2BoxSike.SetPos(-94.5f, 24, 120);

	check2Stand.size = { 1, 4, 1 };
	check2Stand.color = Purple;
	check2Stand.SetPos(-94.5f, 22, 120);
	trackArray.cubeArray.PushBack(check2Stand);
	trackArray.physArray.PushBack(App->physics->AddBody(check2Stand, 0.0f));

	check2Boxiapb.size = { 1, 1, 1 };
	check2Boxiapb.color = Gray;
	check2Boxiapb.SetPos(-105.5f, 24, 120);
	trackArray.cubeArray.PushBack(check2Boxiapb);
	trackArray.physArray.PushBack(App->physics->AddBody(check2Boxiapb, 0.0f));

	check2BoxSikeiapb.size = { 1.1f, 1.1f, 1.1f };
	check2BoxSikeiapb.color = DarkPurple;
	check2BoxSikeiapb.SetPos(-105.5f, 24, 120);

	check2Standiapb.size = { 1, 4, 1 };
	check2Standiapb.color = Purple;
	check2Standiapb.SetPos(-105.5f, 22, 120);
	trackArray.cubeArray.PushBack(check2Standiapb);
	trackArray.physArray.PushBack(App->physics->AddBody(check2Standiapb, 0.0f));
	
	check3.size = { 1, 12, 12 };
	check3p = App->physics->AddBody(check3, 0);
	check3p->SetPos(-150, 25, 182);
	check3p->GetTransform(&check3.transform);
	check3p->SetAsSensor(true);
	check3p->collision_listeners.add(this);

	check3Box.size = { 1, 1, 1 };
	check3Box.color = Gray;
	check3Box.SetPos(-150, 28, 176.5);
	trackArray.cubeArray.PushBack(check3Box);
	trackArray.physArray.PushBack(App->physics->AddBody(check3Box, 0.0f));

	check3BoxSike.size = { 1.1f, 1.1f, 1.1f };
	check3BoxSike.color = DarkPurple;
	check3BoxSike.SetPos(-150, 28, 176.5);

	check3Stand.size = { 1, 4, 1 };
	check3Stand.color = Purple;
	check3Stand.SetPos(-150, 26, 176.5);
	trackArray.cubeArray.PushBack(check3Stand);
	trackArray.physArray.PushBack(App->physics->AddBody(check3Stand, 0.0f));

	check3Boxiapb.size = { 1, 1, 1 };
	check3Boxiapb.color = Gray;
	check3Boxiapb.SetPos(-150, 28, 187.5f);
	trackArray.cubeArray.PushBack(check3Boxiapb);
	trackArray.physArray.PushBack(App->physics->AddBody(check3Boxiapb, 0.0f));

	check3BoxSikeiapb.size = { 1.1f, 1.1f, 1.1f };
	check3BoxSikeiapb.color = DarkPurple;
	check3BoxSikeiapb.SetPos(-150, 28, 187.5f);

	check3Standiapb.size = { 1, 4, 1 };
	check3Standiapb.color = Purple;
	check3Standiapb.SetPos(-150, 26, 187.5f);
	trackArray.cubeArray.PushBack(check3Standiapb);
	trackArray.physArray.PushBack(App->physics->AddBody(check3Standiapb, 0.0f));
	
	check4.size = { 12, 12, 1 };
	check4p = App->physics->AddBody(check4, 0);
	check4p->SetPos(100, 21, 21);
	check4p->GetTransform(&check4.transform);
	check4p->SetAsSensor(true);
	check4p->collision_listeners.add(this);

	check4Box.size = { 1, 1, 1 };
	check4Box.color = Gray;
	check4Box.SetPos(105.5f, 24, 21);
	trackArray.cubeArray.PushBack(check4Box);
	trackArray.physArray.PushBack(App->physics->AddBody(check4Box, 0.0f));

	check4BoxSike.size = { 1.1f, 1.1f, 1.1f };
	check4BoxSike.color = DarkPurple;
	check4BoxSike.SetPos(105.5f, 24, 21);

	check4Stand.size = { 1, 4, 1 };
	check4Stand.color = Purple;
	check4Stand.SetPos(105.5f, 22, 21);
	trackArray.cubeArray.PushBack(check4Stand);
	trackArray.physArray.PushBack(App->physics->AddBody(check4Stand, 0.0f));

	check4Boxiapb.size = { 1, 1, 1 };
	check4Boxiapb.color = Gray;
	check4Boxiapb.SetPos(94.5f, 24, 21);
	trackArray.cubeArray.PushBack(check4Boxiapb);
	trackArray.physArray.PushBack(App->physics->AddBody(check4Boxiapb, 0.0f));

	check4BoxSikeiapb.size = { 1.1f, 1.1f, 1.1f };
	check4BoxSikeiapb.color = DarkPurple;
	check4BoxSikeiapb.SetPos(94.5f, 24, 21);

	check4Standiapb.size = { 1, 4, 1 };
	check4Standiapb.color = Purple;
	check4Standiapb.SetPos(94.5f, 22, 21);
	trackArray.cubeArray.PushBack(check4Standiapb);
	trackArray.physArray.PushBack(App->physics->AddBody(check4Standiapb, 0.0f));

	check1Passed = false;
	check2Passed = false;
	check3Passed = false;
	check4Passed = false;

	death.size = { 1000, 2, 1000 };
	deathP = App->physics->AddBody(death, 0);
	deathP->SetPos(0, 1, 100);
	deathP->GetTransform(&death.transform);
	deathP->SetAsSensor(true);
	deathP->collision_listeners.add(this);

	cyl.radius = 2;
	cyl.height = 6;
	cyl.SetRotation(-90, { 0.0f, 0.0f, 1.0f });
	cylP = App->physics->AddBody(cyl, 0);
	cyl.SetPos(95.0f, 23, 90);
	cyl.color = DarkPurple;

	Cube* door = new Cube();
	door->size = { 45, 1, 5 };
	door->SetRotation(-90, { 1.0f, 0.0f, 0.0f, });
	door->SetPos(95.5f, 20, 90);
	door->body = App->physics->AddBody(*door, 10000000.0f);
	doorC = door;
	door->color = DarkPurple;

	checkpointCount = 0;
	startMusic = true;
	gameMusic = true;
	finishMusic = true;
	start = false;
	timerFx = 0;
	timerMusic = 0;

	musicFx = App->audio->LoadFx("Assets/Audio/Music/game_music.ogg");
	victoryFx = App->audio->LoadFx("Assets/Audio/Music/victory.ogg");
	loseFx = App->audio->LoadFx("Assets/Audio/Fx/lose.ogg");
	clapFx = App->audio->LoadFx("Assets/Audio/Fx/clap.ogg");

	finishLineFx = App->audio->LoadFx("Assets/Fx/finish.wav");
	startFx = App->audio->LoadFx("Assets/Audio/Music/start.wav");
	oneFx = App->audio->LoadFx("Assets/Audio/Fx/one.wav");
	twoFx = App->audio->LoadFx("Assets/Audio/Fx/two.wav");
	threeFx = App->audio->LoadFx("Assets/Audio/Fx/three.wav");
	goFx = App->audio->LoadFx("Assets/Audio/Fx/go.wav");
	checkpointFx = App->audio->LoadFx("Assets/Audio/Fx/checkpoint.wav");

	return ret;
}

bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.color = Black;
	p.Render();

	doorC->Update();
	doorC->body->GetBody()->setAngularVelocity({ 0, 2.5f, 0 });


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
			App->audio->PlayFx(threeFx, 0);
		}

		if (timerFx > 280 && timerFx < 282)
		{
			App->audio->PlayFx(twoFx, 0);
		}

		if (timerFx > 360 && timerFx < 362)
		{
			App->audio->PlayFx(oneFx, 0);
		}

		if (timerFx > 440 && timerFx < 442)
		{
			App->audio->PlayFx(goFx, 0);
			timerFx = 0;
		}
		timerFx++;
	}

	if (start)
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
		if (timerMusic < 2) App->audio->StopFx(-1);

		if (finishMusic)
		{
			if (timerMusic > 10)
			{
				App->audio->PlayFx(loseFx, 0);
				finishMusic = false;
			}
		}
		timerMusic++;
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

	for (int i = 0; i < trackArray.cubeArray.Count(); i++)
	{
		trackArray.cubeArray[i].Render();
	}

	cyl.Render();
	doorC->Render();

	if (check2Passed)
	{
		check2BoxSike.Render();
		check2BoxSikeiapb.Render();
	}

	if (check3Passed)
	{
		check3BoxSike.Render();
		check3BoxSikeiapb.Render();
	}

	if (check4Passed)
	{
		check4BoxSike.Render();
		check4BoxSikeiapb.Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body2 == (PhysBody3D*)App->player->vehicle)
	{
		if (body1 == check1p)
		{
			if (checkpointCount == 4)
			{
				App->player->isWon = true;
			}
			if (!check1Passed)
			{
				checkpointCount++;
				check1Passed = true;
			}
		}
		else if (body1 == check2p && !check2Passed)
		{
			App->player->SetCheckpointPosition();
			App->audio->PlayFx(checkpointFx);
			checkpointCount++;
			check2Passed = true;
		}
		else if (body1 == check3p && !check3Passed)
		{
			App->player->SetCheckpointPosition();
			App->audio->PlayFx(checkpointFx);
			checkpointCount++;
			check3Passed = true;
		}
		else if (body1 == check4p && !check4Passed)
		{
			App->player->SetCheckpointPosition();
			App->audio->PlayFx(checkpointFx);
			checkpointCount++;
			check4Passed = true;
		}
		else if (body1 == deathP)
		{
			App->audio->PlayFx(App->player->honkFx);
			--App->player->lives;
			App->player->vehicle->vehicle->getRigidBody()->setLinearVelocity(btVector3(0, 0, 0));
			App->player->vehicle->vehicle->getRigidBody()->setWorldTransform(App->player->checkpointTransf);
		}
	}
}

void ModuleSceneIntro::CreateCurve(vec3 curvePos, float curveLength, float curveInitialAngle, float curveFinalAngle, float radius, Color curveColor)
{
	vec3 size = { 12.0f, 1.0f, curveLength };
	Cube curve;
	curve.size = size;
	curve.color = curveColor;
	float pi = 3.141592f;
	float initialPosX = curvePos.x;
	float initialPosZ = curvePos.z;
	for (float angle = curveInitialAngle; angle < curveFinalAngle; angle += 1.0f)
	{
		curve.SetRotation(-angle, { 0.0f, 1.0f, 0.0f });
		angle = angle * (pi / 180.0f);
		curve.SetPos(curvePos.x, curvePos.y, curvePos.z);
		trackArray.cubeArray.PushBack(curve);
		trackArray.physArray.PushBack(App->physics->AddBody(curve, 0.0f));
		if (curveInitialAngle == 0)
		{
			curvePos.z = radius * sin(angle) + initialPosZ;
			curvePos.x = -(radius - (radius * cos(angle))) + initialPosX;
		}
		else if (curveInitialAngle == 90)
		{
			curvePos.z = -(radius - (radius * sin(angle))) + initialPosZ;
			curvePos.x = (radius * cos(angle)) + initialPosX;
		}
		else if (curveInitialAngle == 180)
		{
			curvePos.z = (radius * sin(angle)) + initialPosZ;
			curvePos.x = (radius + (radius * cos(angle))) + initialPosX;
		}
		else if (curveInitialAngle == 270)
		{
			curvePos.z = (radius + (radius * sin(angle))) + initialPosZ;
			curvePos.x = (radius * cos(angle)) + initialPosX;
		}
		angle = angle * (180.0f / pi);
	}
}

void ModuleSceneIntro::CreateWall(vec3 wallPos, float wallLength, float wallAngle, Color wallColor)
{
	Cube wall;
	vec3 size = { wallLength, 6.0f, 1.0f };
	wall.size = size;
	wall.color = wallColor;
	wall.SetRotation(-wallAngle, { 0.0f, 1.0f, 0.0f });
	wall.SetPos(wallPos.x, wallPos.y, wallPos.z + 3);
	trackArray.cubeArray.PushBack(wall);
	trackArray.physArray.PushBack(App->physics->AddBody(wall, 0.0f));
}

void ModuleSceneIntro::CreateRamp(vec3 rampPos, float rampLength, float rampAngle, float rampOrientation, Color rampColor)
{
	vec3 size = { };
	Cube ramp;
	if (rampOrientation == 0.0f)
	{
		size = { 12.0f, 1.0, rampLength };
		ramp.size = size;
		ramp.color = rampColor;
		ramp.SetRotation(-rampAngle, { 1.0f, 0.0f, 0.0f });
		ramp.SetPos(rampPos.x, rampPos.y, rampPos.z);
		trackArray.cubeArray.PushBack(ramp);
		trackArray.physArray.PushBack(App->physics->AddBody(ramp, 0.0f));
	}
	else if (rampOrientation == 1.0f)
	{
		size = { rampLength, 1.0, 12.0f };
		ramp.size = size;
		ramp.color = rampColor;
		ramp.SetRotation(-rampAngle, { 0.0f, 0.0f, 1.0f });
		ramp.SetPos(rampPos.x, rampPos.y, rampPos.z);
		trackArray.cubeArray.PushBack(ramp);
		trackArray.physArray.PushBack(App->physics->AddBody(ramp, 0.0f));
	}
}

void ModuleSceneIntro::CreateTrack(vec3 trackPos, float trackLength, float trackAngle, Color trackColor, float trackWidth)
{
	vec3 size = {};
	Cube platform;
	if (trackAngle == 0.0f)
	{
		size = { trackWidth, 1.0f, trackLength };

		platform.size = size;
		platform.color = trackColor;

		platform.SetPos(trackPos.x, trackPos.y, trackPos.z + 3);
		trackArray.cubeArray.PushBack(platform);
		trackArray.physArray.PushBack(App->physics->AddBody(platform, 0.0f));
	}
	else if (trackAngle == 1.0f)
	{
		size = { trackLength, 1.0f, trackWidth };

		platform.size = size;
		platform.color = trackColor;

		platform.SetPos(trackPos.x + 3, trackPos.y, trackPos.z);
		trackArray.cubeArray.PushBack(platform);
		trackArray.physArray.PushBack(App->physics->AddBody(platform, 0.0f));
	}
}