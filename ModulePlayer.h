#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void SetCheckpointPosition();
	void SetTurnPosition();
	void RestartGame();

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	Timer timer;

	mat4x4 transform;

	int lives = 5;
	int honkFx;
	int time = 0;

	bool isWon;
	bool isLose;

	btTransform checkpointTransf;
	btTransform turnTransf;

	vec3 GetPos();
};