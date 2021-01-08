#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

struct trackArray
{
	p2DynArray<Cube> cubeArray;
	p2DynArray<PhysBody3D*> physArray;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	void Timer();

	void CreateTrack(vec3 trackPos, float trackLength, Color trackColor, float trackAngle, float trackDistance); 
	//void CreateCurve(vec3 curvePos, int curveLength, float curveAngle, Color curveColor);
	//void CreateDoors(vec3 doorPos, float doorAngle, Color doorColor);
	//void CreateRamp(vec3 rampPos, float rampLength, float rampHeight, float rampAngle);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	Cube* wall;
	PhysBody3D* wallA;

	Cube* ground;
	PhysBody3D* groundA;

	trackArray trackArray;
	p2DynArray<Primitive*> arrayTrack;

	// ------------

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
};
