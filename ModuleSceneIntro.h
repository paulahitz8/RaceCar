#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "glut/glut.h"

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

	void CreateCurve(vec3 curvePos, float curveLength, float curveInitialAngle, float curveFinalAngle, float radius, Color curveColor);
	void CreateRamp(vec3 rampPos, float rampLength, float rampAngle, float rampOrientation, Color rampColor);
	void CreateTrack(vec3 trackPos, float trackLength, float trackAngle, Color trackColor, float trackWidth);
	void CreateWall(vec3 wallPos, float wallLength, float wallAngle, Color wallColor);

public:
	
	int musicFx;
	int victoryFx;
	int clapFx;
	int loseFx;
	bool start;
	bool startMusic;
	bool gameMusic;
	bool finishMusic;
	int finishLineFx;
	int startFx;
	int oneFx;
	int twoFx;
	int threeFx;
	int goFx;
	int timerFx;
	int timerMusic;
	

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
