#pragma once
#include "Module.h"
#include "Globals.h"
#include "glmath.h"

class ModuleCamera3DP2 : public Module
{
public:
	ModuleCamera3DP2(Application* app, bool start_enabled = true);
	~ModuleCamera3DP2();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void Look(const vec3 &Position, const vec3 &Reference, bool RotateAroundReference = true);
	void Follow(PhysBody3D* body, float min, float max, float height);
	void UnFollow();
	void Move(const vec3 &Movement);
	float* GetViewMatrix();

private:

	void CalculateViewMatrix();

public:

	vec3 X, Y, Z, Position, Reference, Angle;

private:
	mat4x4 ViewMatrix, ViewMatrixInverse;
	PhysBody3D* following;
	float min_following_dist;
	float max_following_dist;
	float following_height;
};