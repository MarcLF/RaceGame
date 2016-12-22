#include "Globals.h"
#include "Application.h"
#include "ModulePlayer2.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "ModuleSceneIntro.h"

ModulePlayer2::ModulePlayer2(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle2(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 1, 4);
	car.chassis_offset.Set(0, 1, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 11.85f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.3;
	car.maxSuspensionTravelCm = 500.0f;
	car.frictionSlip = 1000;
	car.maxSuspensionForce = 6000.0f;
	//Timer
	seconds = 0;
	minutes = 0;
	miliseconds = 0;
	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;

	vec3 direction(0, -1, 0);
	vec3 axis(-1, 0, 0);

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

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

	vehicle2 = App->physics->AddVehicleP2(car);
	vehicle2->SetPos(-1, 27, 30);

	//vehicle->SetPos(184, 12 + 15, 672.6-1.3);
	//vehicle->SetPos(303.3 - 0.6, 8.35, 803.9 + 0.2);
	App->camerap2->Follow(vehicle2, 10, 20, 1.f);
	return true;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
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

	if (App->input->GetKey(SDL_SCANCODE_0) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
	}
	if (App->input->GetKey(SDL_SCANCODE_P) == KEY_UP || App->scene_intro->fallen2)
	{
		if (App->scene_intro->sen2_1 == false) {
			vehicle2->SetPos(20, 27, 30);
			vehicle2->SetTransform(IdentityMatrix.M);
			vehicle2->body->setLinearVelocity(btVector3(0, 0, 0));
			vehicle2->body->setAngularVelocity(btVector3(0, 0, 0));
			brake = BRAKE_POWER;
			App->scene_intro->fallen2 = false;
		}
		if (App->scene_intro->sen2_1 == true) {
			vehicle2->SetTransform(IdentityMatrix.M);
			vehicle2->SetPos(0.9, 27, 562);

			vehicle2->body->setLinearVelocity(btVector3(0, 0, 0));
			vehicle2->body->setAngularVelocity(btVector3(0, 0, 0));
			brake = BRAKE_POWER;
			App->scene_intro->fallen2 = false;
		}
		if (App->scene_intro->sen2_2 == true) {
			vehicle2->SetTransform(IdentityMatrix.M);
			vehicle2->SetPos(302, 27, 726.07);
			vehicle2->body->setLinearVelocity(btVector3(0, 0, 0));
			vehicle2->body->setAngularVelocity(btVector3(0, 320, 0));
			brake = BRAKE_POWER;
			App->scene_intro->fallen2 = false;
		}
		if (App->scene_intro->sen2_3 == true) {
			vehicle2->SetPos(184, 27, 671.3);
			vehicle2->body->setLinearVelocity(btVector3(0, 0, 0));
			vehicle2->body->setAngularVelocity(btVector3(0, 65, 0));
			brake = BRAKE_POWER;
			App->scene_intro->fallen2 = false;
		}
		if (App->scene_intro->sen2_4 == true) {
			vehicle2->SetPos(125.2, 27, 254.4);
			vehicle2->body->setLinearVelocity(btVector3(0, 0, 0));
			vehicle2->body->setAngularVelocity(btVector3(0, 320, 0));
			brake = BRAKE_POWER;

			App->scene_intro->fallen2 = false;
		}
	}
	miliseconds++;
	if (miliseconds == 59) {
		miliseconds = 0;
		seconds++;
	}
	if (seconds == 59) {
		seconds = 0;
		minutes++;
	}
	minutesrecord = 0;
	secondsrecord = 0;
	vehicle2->ApplyEngineForce(acceleration);
	vehicle2->Turn(turn);
	vehicle2->Brake(brake);

	vehicle2->Render();
	Kmh = vehicle2->GetKmh();

	title2.create("Player2: %.1f Km/h | %d m | %d s | Best Lap:", Kmh, minutes, seconds, minutesrecord, secondsrecord);

	return UPDATE_CONTINUE;
}



