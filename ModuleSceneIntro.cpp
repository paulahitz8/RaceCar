#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

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

	wall->Render();
	//ground->Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void CreateTrack(vec3 trackPos, float trackLength, float trackAngle, float trackDistance, Color trackColor);
void CreateCurve(vec3 curvePos, int curveLength, float curveAngle, Color curveColor);
//void CreateTrackLine(vec3 LineTrackPos, float LineTrackLength, Color LineTrackColor, float LineTrackAngle);
void CreateDoors(vec3 doorPos, float doorAngle, Color doorColor);
void CreateRamp(vec3 rampPos, float rampLength, float rampHeight, float rampAngle);

