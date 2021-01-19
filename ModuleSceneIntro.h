#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "glut/glut.h"
#include "PhysBody3D.h"

#define MAX_SNAKE 2

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
	void CreateCheckpoint(vec3 checkpointPos, bool rotate, PhysBody3D::Tag type);
	void CheckpointPassed(PhysBody3D* checkpoint_body);

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
	int checkpointFx;
	int timerFx;
	int timerMusic;
	
	p2DynArray <Cube> checkpointCube;
	p2DynArray <PhysBody3D*> checkpointPhys;

	Cube checkTest;
	PhysBody3D* testp;

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
