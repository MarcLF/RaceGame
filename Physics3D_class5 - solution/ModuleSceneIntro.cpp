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
	for (n = 0; n<80; ++n)
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

	c[10].size.Set(road_width, road_height, 15);
	c[10].SetPos(0, 12.2+5 + 15, 112.5 + 268.6);
	c[10].SetRotation(20, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[10], 0);

	c[11].size.Set(road_width, road_height, 15);
	c[11].SetPos(0, 8.3 + 39+5 + 15, 80.5 + 126.8+107.8);
	c[11].SetRotation(20, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[11], 0);

	c[12].size.Set(road_width, road_height, 15);
	c[12].SetPos(0, 39 + 12.1+5 + 15, 80.5 + 112.5 +108);
	c[12].SetRotation(10, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[12], 0);

	c[13].size.Set(road_width, road_height, 150);
	c[13].SetPos(0, 12 + 15, 30+448);
	App->physics->AddBody(c[13], 0);

	//Curve

	c[14].size.Set(road_width, road_height, 20);
	c[14].SetPos(0.9, 12 + 15, 562);
	c[14].SetRotation(5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[14], 0);

	c[15].size.Set(road_width, road_height, 20);
	c[15].SetPos(3.4, 12 + 15, 581);
	c[15].SetRotation(10, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[15], 0);
	
	c[16].size.Set(road_width, road_height, 20);
	c[16].SetPos(7.6, 12 + 15, 600);
	c[16].SetRotation(15, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[16], 0);
	
	c[17].size.Set(road_width, road_height, 20);
	c[17].SetPos(13.3, 12 + 15, 618);
	c[17].SetRotation(20, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[17], 0);
	
	c[18].size.Set(road_width, road_height, 20);
	c[18].SetPos(20.8, 12 + 15, 636);
	c[18].SetRotation(25, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[18], 0);

	c[19].size.Set(road_width, road_height, 20);
	c[19].SetPos(29.7, 12 + 15, 653);
	c[19].SetRotation(30, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[19], 0);

	c[20].size.Set(road_width, road_height, 20);
	c[20].SetPos(39.95, 12 + 15, 669);
	c[20].SetRotation(35, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[20], 0);
	
	c[21].size.Set(road_width, road_height, 20);
	c[21].SetPos(50.8, 12 + 15, 683);
	c[21].SetRotation(40, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[21], 0);

	c[22].size.Set(road_width, road_height, 150);
	c[22].SetPos(109.7, 12 + 15, 743);
	c[22].SetRotation(45, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[22], 0);

	c[23].size.Set(road_width, road_height, 30);
	c[23].SetPos(174.9, 12 + 15, 800.3);
	c[23].SetRotation(67.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[23], 0);

	c[24].size.Set(road_width, road_height, 30);
	c[24].SetPos(201.5, 12 + 15, 805.5);
	c[24].SetRotation(90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[24], 0);
	
	c[25].size.Set(60, road_height, road_width);
	c[25].SetPos(268, 12 + 15, 806.5);
	App->physics->AddBody(c[25], 0);

	c[26].size.Set(road_width, road_height, 10);
	c[26].SetPos(201.5, 12 + 15, 805.5);
	c[26].SetRotation(7.5, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[26], 0);

	c[27].size.Set(road_width, road_height, 10);
	c[27].SetPos(213, 9.3+5 + 15, 805.5);
	c[27].SetRotation(15, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[27], 0);
	//
	
	c[28].size.Set(road_width, road_height, 15);
	c[28].SetPos(303.3-0.6, 12 + 15, 803.9+0.2);
	c[28].SetRotation(112.5, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[28], 0);
	
	c[29].size.Set(road_width, road_height, 15);
	c[29].SetPos(312, 12 + 15, 798);
	c[29].SetRotation(135, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[29], 0);
	
	c[30].size.Set(road_width, road_height, 18);
	c[30].SetPos(321.5-2.8, 12 + 15, 785.7+2);
	c[30].SetRotation(157.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[30], 0);
	
	c[50].size.Set(road_width, road_height, 60);
	c[50].SetPos(324-2.3, 12 + 15, 752);
	c[50].SetRotation(180, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[50], 0);
	
	c[31].size.Set(50, road_height, road_width*2/3);
	c[31].SetPos(302, 12 + 15, 722.67+3.4);
	App->physics->AddBody(c[31], 0);

	c[32].size.Set(road_width * 2 / 3, road_height, 50);
	c[32].SetPos(278, 12 + 15, 700.34+4.75);
	App->physics->AddBody(c[32], 0);
	//
	c[33].size.Set(50, road_height, road_width * 2 / 3);
	c[33].SetPos(255, 12 + 15, 678+6);
	App->physics->AddBody(c[33], 0);

	c[34].size.Set(50, road_height, road_width * 2 / 3);
	c[34].SetPos(270-65, 12 + 15, 722.67+4.75);
	App->physics->AddBody(c[34], 0);

	c[35].size.Set(road_width * 2 / 3, road_height, 50);
	c[35].SetPos(278-52, 12 + 15, 700.34+4.75);
	App->physics->AddBody(c[35], 0);

	c[36].size.Set(road_width * 2 / 3, road_height, 50);
	c[36].SetPos(278 -94, 12 + 15, 700.34);
	App->physics->AddBody(c[36], 0);

	//Pieces with movement.

	c[37].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[37].SetPos(184, 12 + 15, 672.6-1.3);
	App->physics->AddBody(c[37], 0);

	c[38].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[38].SetPos(184, 12 + 15, 667.2-3.95);
	App->physics->AddBody(c[38], 0);

	c[39].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[39].SetPos(184, 12 + 15, 661.8-6.6);
	App->physics->AddBody(c[39], 0);

	c[40].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[40].SetPos(184, 12 + 15, 656.4-9.25);
	App->physics->AddBody(c[40], 0);

	c[41].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[41].SetPos(184, 12 + 15, 651-11.9);
	App->physics->AddBody(c[41], 0);

	//Curve for d
	c[52].size.Set(road_width , road_height,350);
	c[52].SetPos(184, 12 + 15, 460);
	App->physics->AddBody(c[52], 0);

	c[53].size.Set(road_width, road_height, 15);
	c[53].SetPos(182, 27, 350- 67.05);
	c[53].SetRotation(18, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[53], 0);

	c[54].size.Set(road_width, road_height, 15);
	c[54].SetPos(176.15, 27, 338.5- 67.05);
	c[54].SetRotation(36, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[54], 0);

	c[55].size.Set(road_width, road_height, 15);
	c[55].SetPos(167, 27, 329.4- 67.05);
	c[55].SetRotation(54, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[55], 0);

	c[56].size.Set(road_width, road_height, 15);
	c[56].SetPos(155.5, 27 , 323.5 - 67.05);
	c[56].SetRotation(72, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[56], 0);

	c[51].size.Set(50, road_height, road_width);
	c[51].SetPos(125.2, 27, 30 + 224.4);
	App->physics->AddBody(c[51], 0);

	//Up PF

	c[57].size.Set(7.5, road_height, road_width);
	c[57].SetPos(97, 27.6, 30 + 224.4);
	c[57].SetRotation(11.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[57], 0);

	c[58].size.Set(7.5, road_height, road_width);
	c[58].SetPos(89.7, 29.8, 30 + 224.4);
	c[58].SetRotation(22.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[58], 0);

	c[59].size.Set(30, road_height, road_width);
	c[59].SetPos(73.5, 39.7, 30 + 224.4);
	c[59].SetRotation(33.75, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[59], 0);

	c[60].size.Set(7.5, road_height, road_width);
	c[60].SetPos(57.8, 49.32, 30 + 224.4);
	c[60].SetRotation(22.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[60], 0);

	c[0].size.Set(7.5, road_height, road_width);
	c[0].SetPos(0, 15, 30 + 224.4);
	c[0].SetRotation(0, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[0], 0);
	
	c[61].size.Set(7.5, road_height, road_width);
	c[61].SetPos(50.9, 51.4, 30 + 224.4);
	c[61].SetRotation(11.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[61], 0);

	c[62].size.Set(15, road_height, road_width);
	c[62].SetPos(40, 52.1, 30 + 224.4);
	App->physics->AddBody(c[62], 0);

	//DownPF
	c[63].size.Set(7.5, road_height, road_width);
	c[63].SetPos(22.2, 49.32, 30 + 224.4);
	c[63].SetRotation(22.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[63], 0);

	c[64].size.Set(7.5, road_height, road_width);
	c[64].SetPos(29.1, 51.4, 30 + 224.4);
	c[64].SetRotation(11.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[64], 0);
	//LineD
	c[65].size.Set(40, road_height, road_width);
	c[65].SetPos(2.4, 36.94, 30 + 224.4);
	c[65].SetRotation(33.75, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[65], 0);

	//DPF
	c[66].size.Set(35, road_height, road_width);
	c[66].SetPos(-5.2-15.8 - 1.55, 6.35 + 23.62 + 0.1 - 9.8, 30 + 224.4);
	c[66].SetRotation(33.75, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[66], 0);

	c[67].size.Set(7.5, road_height, road_width);
	c[67].SetPos(-14.7-22.6-1.55, 10.3, 30 + 224.4);
	c[67].SetRotation(22.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[67], 0);
	
	c[68].size.Set(7.5, road_height, road_width);
	c[68].SetPos(-14.7-30-1.55, 8.05, 30 + 224.4);
	c[68].SetRotation(11.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[68], 0);

	


	//Down
	c[43].size.Set(120, road_height, road_width);
	c[43].SetPos(-100, 7.3, 30 + 224.4);
	App->physics->AddBody(c[43], 0);

	c[44].size.Set(60, road_height,road_width);
	c[44].SetPos(-94.5, 7.3, -37.5);
	App->physics->AddBody(c[44], 0);

	//Final Ramp

	c[45].size.Set(road_width, road_height, 15);
	c[45].SetPos(-58.7,8.35, -37.5);
	c[45].SetRotation(10, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[45], 0);

	c[46].size.Set(road_width, road_height, 15);
	c[46].SetPos(-47, 11.4, -37.5);
	c[46].SetRotation(20, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[46], 0);

	c[47].size.Set(15, road_height, 15);
	c[47].SetPos(-34.7, 2.26 + 15, -37.5);
	c[47].SetRotation(30, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[47], 0);

	c[48].size.Set(road_width, road_height, 15);
	c[48].SetPos(-22.8, 7.95 + 15, -37.5);
	c[48].SetRotation(200, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[48], 0);

	c[49].size.Set(road_width, road_height, 15);
	c[49].SetPos(-11.5, 11 + 15,-37.5);
	c[49].SetRotation(190, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[49], 0);
	
	/////// Curve final ramp182
	
	c[69].size.Set(road_width, road_height, 15);
	c[69].SetPos(-129.5, 7.3, -35.5);
	c[69].SetRotation(18+90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[69], 0);

	c[70].size.Set(road_width, road_height, 15);
	c[70].SetPos(-140.9, 7.3, -29.7);
	c[70].SetRotation(36+90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[70], 0);

	c[71].size.Set(road_width, road_height, 15);
	c[71].SetPos(-150, 7.3, -20.5);
	c[71].SetRotation(54+90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[71], 0);

	c[72].size.Set(road_width, road_height, 15);
	c[72].SetPos(-155.8, 7.3, -9);
	c[72].SetRotation(72+90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[72], 0);

	c[73].size.Set(road_width, road_height, 270);
	c[73].SetPos(-159, 7.3, 125);
	App->physics->AddBody(c[73], 0);




	


	//Sensor
	s[1].size = vec3(1000, 1, 2000);
	s[1].SetPos(0, 0, 0);

	sensor[1] = App->physics->AddBody(s[1], 0.0f);
	sensor[1]->SetAsSensor(true);
	sensor[1]->collision_listeners.add(this);


	s[2].size = vec3(road_width, 7, 1);
	s[2].SetPos(0.9, 12 + 15, 562);
	sensor[2] = App->physics->AddBody(s[2], 0.0f);
	sensor[2]->SetAsSensor(true);
	sensor[2]->collision_listeners.add(this);

	s[3].size = vec3(1, 3, road_width - 2);
	s[3].SetPos(302, 12 + 15+3, 722.67 + 3.4);
	sensor[3] = App->physics->AddBody(s[3], 0.0f);
	sensor[3]->SetAsSensor(true);
	sensor[3]->collision_listeners.add(this);

	s[4].size = vec3(road_width, 7, 1);
	s[4].SetPos(278 - 94, 4+12 + 15, 700.34);
	sensor[4] = App->physics->AddBody(s[4], 0.0f);
	sensor[4]->SetAsSensor(true);
	sensor[4]->collision_listeners.add(this);

	s[5].size = vec3(road_width, 7, 1);
	s[5].SetPos(0, 27, 15);
	sensor[5] = App->physics->AddBody(s[5], 0.0f);
	sensor[5]->SetAsSensor(true);
	sensor[5]->collision_listeners.add(this);
	//	//x=0,	y=56.1,	z=193	2, 27, 30
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
	for (n = 0; n<80; ++n)
	{
		c[n].Render();
	}
	sensor[1]->GetTransform(&s[1].transform);
	s[1].Render();
	sensor[2]->GetTransform(&s[2].transform);
	s[2].Render();
	sensor[3]->GetTransform(&s[3].transform);
	s[3].Render();
	sensor[4]->GetTransform(&s[4].transform);
	s[4].Render();
	sensor[5]->GetTransform(&s[5].transform);
	s[5].Render();
	
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

