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
	int minutes, n;
	int seconds;

	int Main_song;
	int Crash_fx;
	int Sound_win;
	
	Cube c[80];
	Cube w[30];
	PhysBody3D* pb_chassis;
	Cube p_chassis;
	
	Cube sensor_form;

	Cube sensor_form2;
	Cube sensor_floor;

	PhysBody3D* sensor_1;
	PhysBody3D* sensor_2;
	PhysBody3D* sensor_3;
	PhysBody3D* sensor_4;
	PhysBody3D* sensor_flo;
	
	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	bool fallen;
	bool fallen2;

	bool sen_1;
	bool sen_2;
	bool sen_3;
	bool sen_4;
	bool sen2_1;
	bool sen2_2;
	bool sen2_3;
	bool sen2_4;


	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
};
