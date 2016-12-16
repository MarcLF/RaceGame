#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	minutes = 0;
	seconds = 0;
	App->camera->Move(vec3(-1.0f, 0.0f, -10.0f));


	float road_width = 12.0f;
	float road_height = 3.0f;

	c[1].size.Set(road_width, road_height, 150);
	c[1].SetPos(0, 7+8+12, 30);
	App->physics->AddBody(c[1], 0)->collision_listeners.add(this);
	
	//Ramp 1 - UP
	for (n = 0; n<60; ++n)
	{
		c[n].color = White;
	}

	c[2].size.Set(road_width, road_height, 15);
	c[2].SetPos(0, 13.3+ 15, 112.5);
	c[2].SetRotation(10, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[2], 0);
	
	c[3].size.Set(road_width, road_height, 15);
	c[3].SetPos(0, 17.2+ 15, 127);
	c[3].SetRotation(20, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[3], 0);

	c[4].size.Set(road_width, road_height, 60);
	c[4].SetPos(0, 34.9 + 15, 160.3);
	c[4].SetRotation(30, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[4], 0);

	c[5].size.Set(road_width, road_height, 15);
	c[5].SetPos(0, 52.3 + 15, 193);
	c[5].SetRotation(200, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[5], 0);

	c[6].size.Set(road_width, road_height, 15);
	c[6].SetPos(0,56.1 + 15, 207.3);
	c[6].SetRotation(190, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[6], 0);

	c[7].size.Set(road_width, road_height, 80);
	c[7].SetPos(0, 57.35 + 15, 254.4);
	App->physics->AddBody(c[7], 0);
	
	//Ramp 2 - Down

	c[8].size.Set(road_width, road_height, 15);
	c[8].SetPos(0, 8.3+5 + 15, 127+268.6);
	c[8].SetRotation(10, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[8], 0);

	c[9].size.Set(road_width, road_height, 60);
	c[9].SetPos(0, 29.9+5 + 15, 200+147.8);
	c[9].SetRotation(30, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[9], 0);

	c[48].size.Set(road_width, road_height, 15);
	c[48].SetPos(0, 12.2+5 + 15, 112.5 + 268.6);
	c[48].SetRotation(20, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[48], 0);

	c[10].size.Set(road_width, road_height, 15);
	c[10].SetPos(0, 8.3 + 39+5 + 15, 80.5 + 126.8+107.8);
	c[10].SetRotation(20, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[10], 0);

	c[11].size.Set(road_width, road_height, 15);
	c[11].SetPos(0, 39 + 12.1+5 + 15, 80.5 + 112.5 +108);
	c[11].SetRotation(10, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[11], 0);

	c[12].size.Set(road_width, road_height, 150);
	c[12].SetPos(0, 12 + 15, 30+448);
	App->physics->AddBody(c[12], 0);

	//Curve

	c[13].size.Set(road_width, road_height, 20);
	c[13].SetPos(0.9, 12 + 15, 562);
	c[13].SetRotation(5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[13], 0);

	c[14].size.Set(road_width, road_height, 20);
	c[14].SetPos(3.4, 12 + 15, 581);
	c[14].SetRotation(10, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[14], 0);
	
	c[15].size.Set(road_width, road_height, 20);
	c[15].SetPos(7.6, 12 + 15, 600);
	c[15].SetRotation(15, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[15], 0);
	
	c[16].size.Set(road_width, road_height, 20);
	c[16].SetPos(13.3, 12 + 15, 618);
	c[16].SetRotation(20, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[16], 0);
	
	c[17].size.Set(road_width, road_height, 20);
	c[17].SetPos(20.8, 12 + 15, 636);
	c[17].SetRotation(25, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[17], 0);

	c[18].size.Set(road_width, road_height, 20);
	c[18].SetPos(29.7, 12 + 15, 653);
	c[18].SetRotation(30, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[18], 0);

	c[19].size.Set(road_width, road_height, 20);
	c[19].SetPos(39.95, 12 + 15, 669);
	c[19].SetRotation(35, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[19], 0);
	
	c[20].size.Set(road_width, road_height, 20);
	c[20].SetPos(50.8, 12 + 15, 683);
	c[20].SetRotation(40, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[20], 0);

	c[21].size.Set(road_width, road_height, 150);
	c[21].SetPos(109.7, 12 + 15, 743);
	c[21].SetRotation(45, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[21], 0);

	c[22].size.Set(road_width, road_height, 30);
	c[22].SetPos(174.9, 12 + 15, 800.3);
	c[22].SetRotation(67.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[22], 0);

	c[23].size.Set(road_width, road_height, 30);
	c[23].SetPos(201.5, 12 + 15, 805.5);
	c[23].SetRotation(90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[23], 0);
	
	c[24].size.Set(60, road_height, road_width);
	c[24].SetPos(268, 12 + 15, 806.5);
	App->physics->AddBody(c[24], 0);

	c[40].size.Set(road_width, road_height, 10);
	c[40].SetPos(201.5, 12 + 15, 805.5);
	c[40].SetRotation(7.5, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[40], 0);

	c[41].size.Set(road_width, road_height, 10);
	c[41].SetPos(213, 9.3+5 + 15, 805.5);
	c[41].SetRotation(15, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[41], 0);
	//
	
	c[25].size.Set(road_width, road_height, 15);
	c[25].SetPos(303.3-0.6, 12 + 15, 803.9+0.2);
	c[25].SetRotation(112.5, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[25], 0);
	
	c[26].size.Set(road_width, road_height, 15);
	c[26].SetPos(314.2-1.7, 12 + 15, 796.6+0.8);
	c[26].SetRotation(135, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[26], 0);
	
	c[27].size.Set(road_width, road_height, 18);
	c[27].SetPos(321.5-2.8, 12 + 15, 785.7+2);
	c[27].SetRotation(157.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[27], 0);
	
	c[28].size.Set(road_width, road_height, 60);
	c[28].SetPos(324-2.3, 12 + 15, 752);
	c[28].SetRotation(180, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[28], 0);
	
	c[29].size.Set(50, road_height, road_width*2/3);
	c[29].SetPos(302, 12 + 15, 722.67+3.4);
	App->physics->AddBody(c[29], 0);

	c[30].size.Set(road_width * 2 / 3, road_height, 50);
	c[30].SetPos(278, 12 + 15, 700.34+4.75);
	App->physics->AddBody(c[30], 0);
	//
	c[31].size.Set(50, road_height, road_width * 2 / 3);
	c[31].SetPos(255, 12 + 15, 678+6);
	App->physics->AddBody(c[31], 0);

	c[32].size.Set(50, road_height, road_width * 2 / 3);
	c[32].SetPos(270-65, 12 + 15, 722.67+4.75);
	App->physics->AddBody(c[32], 0);

	c[33].size.Set(road_width * 2 / 3, road_height, 50);
	c[33].SetPos(278-52, 12 + 15, 700.34+3.4);
	App->physics->AddBody(c[33], 0);

	c[34].size.Set(road_width * 2 / 3, road_height, 50);
	c[34].SetPos(278 -94, 12 + 15, 700.34);
	App->physics->AddBody(c[34], 0);

	//Pieces with movement.

	c[35].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[35].SetPos(184, 12 + 15, 672.6-1.3);
	App->physics->AddBody(c[35], 0);

	c[36].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[36].SetPos(184, 12 + 15, 667.2-3.95);
	App->physics->AddBody(c[36], 0);

	c[37].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[37].SetPos(184, 12 + 15, 661.8-6.6);
	App->physics->AddBody(c[37], 0);

	c[38].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[38].SetPos(184, 12 + 15, 656.4-9.25);
	App->physics->AddBody(c[38], 0);

	c[39].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[39].SetPos(184, 12 + 15, 651-11.9);
	App->physics->AddBody(c[39], 0);

	//
	c[39].size.Set(road_width , road_height,200);
	c[39].SetPos(184, 12 + 15, 549-14);
	App->physics->AddBody(c[39], 0);


	//Down
	c[42].size.Set(160, road_height, road_width);
	c[42].SetPos(0, 2 + 15, 30 + 224.4);
	App->physics->AddBody(c[42], 0);

	c[42].size.Set(60, road_height,15);
	c[42].SetPos(-94.5, 7.3, -37.5);
	App->physics->AddBody(c[42], 0);

	//Final Ramp

	c[43].size.Set(road_width, road_height, 15);
	c[43].SetPos(-58.7,8.35, -37.5);
	c[43].SetRotation(10, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[43], 0);

	c[44].size.Set(road_width, road_height, 15);
	c[44].SetPos(-47, 11.4, -37.5);
	c[44].SetRotation(20, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[44], 0);

	c[45].size.Set(15, road_height, 15);
	c[45].SetPos(-34.7, 2.26 + 15, -37.5);
	c[45].SetRotation(30, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[45], 0);

	c[46].size.Set(road_width, road_height, 15);
	c[46].SetPos(-22.8, 7.95 + 15, -37.5);
	c[46].SetRotation(200, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[46], 0);

	c[47].size.Set(road_width, road_height, 15);
	c[47].SetPos(-11.5, 11 + 15,-37.5);
	c[47].SetRotation(190, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[47], 0);

	c[49].size.Set(road_width, road_height, 15);
	c[49].SetPos(303.3 - 0.6, 12 + 15, 803.9 + 0.2);
	c[49].SetRotation(112.5, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[49], 0);
	//
	c[50].size.Set(road_width, road_height, 15);
	c[50].SetPos(314.2 - 1.7, 12 + 15, 796.6 + 0.8);
	c[50].SetRotation(135, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[50], 0);

	c[51].size.Set(road_width, road_height, 18);
	c[51].SetPos(321.5 - 2.8, 12 + 15, 785.7 + 2);
	c[51].SetRotation(157.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[51], 0);

	c[52].size.Set(road_width, road_height, 60);
	c[52].SetPos(324 - 2.3, 12 + 15, 752);
	c[52].SetRotation(180, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[52], 0);

	c[53].size.Set(50, road_height, road_width * 2 / 3);
	c[53].SetPos(302, 12 + 15, 722.67 + 3.4);
	App->physics->AddBody(c[53], 0);
	//	//x=0,	y=56.1,	z=193
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	for (n = 0; n<60; ++n)
	{
		c[n].Render();
	}


	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

