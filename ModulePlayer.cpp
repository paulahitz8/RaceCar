#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 1, 6);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 600.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.3f;
	float wheel_width = 0.7f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x * 0.5f;
	float half_length = car.chassis_size.z * 0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	car.num_wheels = 8;
	car.wheels = new Wheel[8];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// MIDDLE FRONT-RIGHT ------------------------
	car.wheels[4].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - (4 * wheel_radius));
	car.wheels[4].direction = direction;
	car.wheels[4].axis = axis;
	car.wheels[4].suspensionRestLength = suspensionRestLength;
	car.wheels[4].radius = wheel_radius;
	car.wheels[4].width = wheel_width;
	car.wheels[4].front = true;
	car.wheels[4].drive = true;
	car.wheels[4].brake = false;
	car.wheels[4].steering = true;

	// MIDDLE FRONT-LEFT ------------------------
	car.wheels[5].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - (4 * wheel_radius));
	car.wheels[5].direction = direction;
	car.wheels[5].axis = axis;
	car.wheels[5].suspensionRestLength = suspensionRestLength;
	car.wheels[5].radius = wheel_radius;
	car.wheels[5].width = wheel_width;
	car.wheels[5].front = true;
	car.wheels[5].drive = true;
	car.wheels[5].brake = false;
	car.wheels[5].steering = true;

	// MIDDLE BACK-RIGHT ------------------------
	car.wheels[6].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + (4 * wheel_radius));
	car.wheels[6].direction = direction;
	car.wheels[6].axis = axis;
	car.wheels[6].suspensionRestLength = suspensionRestLength;
	car.wheels[6].radius = wheel_radius;
	car.wheels[6].width = wheel_width;
	car.wheels[6].front = true;
	car.wheels[6].drive = true;
	car.wheels[6].brake = false;
	car.wheels[6].steering = true;

	// MIDDLE BACK-LEFT ------------------------
	car.wheels[7].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + (4 * wheel_radius));
	car.wheels[7].direction = direction;
	car.wheels[7].axis = axis;
	car.wheels[7].suspensionRestLength = suspensionRestLength;
	car.wheels[7].radius = wheel_radius;
	car.wheels[7].width = wheel_width;
	car.wheels[7].front = true;
	car.wheels[7].drive = true;
	car.wheels[7].brake = false;
	car.wheels[7].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetTag(PhysBody3D::Tag::PLAYER);
	vehicle->SetPos(0, 21, 10);
	vehicle->collision_listeners.add(App->scene_intro);

	isWon = false;
	isLose = false;
	lives = 5;

	time = 0;
	
	accel = -1;
	accelFx = App->audio->LoadFx("Assets/Audio/Fx/engine.wav");
	brakeFx = App->audio->LoadFx("Assets/Audio/Fx/brake.wav");
	honkFx = App->audio->LoadFx("Assets/Audio/Fx/honk.wav");
	
	checkpointTransf = vehicle->vehicle->getRigidBody()->getWorldTransform();


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->audio->UnloadFx(honkFx);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;
	time = timer.Read() / 1000;

	if (App->input->GetKey(SDL_SCANCODE_H) == KEY_DOWN)
	{
		App->audio->PlayFx(honkFx);
	}

	if (App->scene_intro->start)
	{
		if (!isWon && !isLose)
		{
			
			if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
			{
				acceleration = MAX_ACCELERATION;
			}

			if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
			{
				if (turn < TURN_DEGREES)
					turn += TURN_DEGREES;
			}

			if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
			{
				if (turn > -TURN_DEGREES)
					turn -= TURN_DEGREES;
			}

			if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
			{
				acceleration = -(MAX_ACCELERATION);
				if (vehicle->GetKmh() > 0)
				{
					//break fx no va
					//App->audio->PlayFx(brakeFx, 0);
				}
			}

			if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
			{
				brake = BRAKE_POWER;
			}

			if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN)
			{
				--lives;
				vehicle->SetPos(0, 0, -100);
				vehicle->Brake(BRAKE_POWER);
				vehicle->SetTransform(&transform);
			}

			if (App->input->GetKey(SDL_SCANCODE_N) == KEY_DOWN)
			{
				isWon = true;
			}

			if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)
			{
				isLose = true;
			}
			if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
			{
				vehicle->vehicle->getRigidBody()->setLinearVelocity(btVector3(0, 0, 0));
				vehicle->vehicle->getRigidBody()->setWorldTransform(checkpointTransf);
			}
		}
		else
		{
			brake = BRAKE_POWER;
		}
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	if (!isWon && !isLose)
	{
		if (time > 8)
		{
			char title[80];
			sprintf_s(title, "%.1f Km/h    Time: %ds   |   GOOOO ", vehicle->GetKmh(), time - 8);
			App->window->SetTitle(title);
		}
		else
		{
			char title[80];
			sprintf_s(title, "%d Km/h    Time: %ds   |   Try to reach the finish line as fast as possible!", 0, 0);
			App->window->SetTitle(title);
		}
	}
	if (isWon)
	{
		char title[80];
		sprintf_s(title, "%.1f Km/h    |   Time: %ds   |   Congratulations, you won!!!", vehicle->GetKmh(), time - 8);
		App->window->SetTitle(title);
	}
	if (isLose)
	{
		char title[80];
		sprintf_s(title, "%.1f Km/h    |   Time: %ds   |   Oh no... you lost... :(", vehicle->GetKmh(), time - 8);
		App->window->SetTitle(title);
	}


	if (lives == 0)
	{
		isLose = true;
	}

	return UPDATE_CONTINUE;
}

vec3 ModulePlayer::GetPos()
{
	vec3 pos;
	pos.x = vehicle->vehicle->getRigidBody()->getCenterOfMassPosition().x();
	pos.y = vehicle->vehicle->getRigidBody()->getCenterOfMassPosition().y();
	pos.z = vehicle->vehicle->getRigidBody()->getCenterOfMassPosition().z();

	return pos;
}


void ModulePlayer::SetCheckpointPosition()
{
	checkpointTransf = vehicle->vehicle->getRigidBody()->getWorldTransform();
}