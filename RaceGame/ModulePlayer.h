#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2SString.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1700.0f
#define TURN_DEGREES 10.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

public:
	
	PhysVehicle3D* vehicle;
	int miliseconds, seconds, minutes, minutesrecord, secondsrecord;
	int engine_fx, brake_fx;
	float turn;
	float acceleration;
	float brake;
	float Kmh;
	bool recover_camera;
	const char* title_print;
	p2SString title;
};