#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "p2Point.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/
	
	Cube s[10];
	int n;

	int Main_song;
	int Crash_fx;
	int P1_Win;
	int P2_Win;
	
	Cube c[80];
	Cube w[14];
	PhysBody3D* pb_chassis;
	Cube p_chassis;
	
	Cube sensor_form;
	Cube sensor_finish;
	Cube sensor_form2;
	Cube sensor_floor;

	PhysBody3D* sensor_1;
	PhysBody3D* sensor_2;
	PhysBody3D* sensor_3;
	PhysBody3D* sensor_4;
	PhysBody3D* sensor_5;
	PhysBody3D* sensor_flo;
	
	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	bool fallen;
	bool fallen2;
	bool winnerp1;
	bool winnerp2;

	bool sen_1 = false;
	bool sen_2 = false;
	bool sen_3 = false;
	bool sen_4 = false;
	bool sen2_1 = false;
	bool sen2_2 = false;
	bool sen2_3 = false;
	bool sen2_4 = false;

	PhysBody3D* doorbody[2];
	btHingeConstraint* doorhinge;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	void allfalse();

};
