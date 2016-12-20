#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2SString.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer2();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	p2SString title2;
public:

	PhysVehicle3D* vehicle2;
	int miliseconds, seconds, minutes, minutesrecord, secondsrecord;

	float turn;
	float acceleration;
	float brake;
	float Kmh;
};