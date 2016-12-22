#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysics3D.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
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
	App->camerap2->Move(vec3(-1.0f, 0.0f, -10.0f));

	App->audio->PlayMusic("Game/Music/Soundtrack.ogg", 1);
	Crash_fx = App->audio->LoadFx("Game/Fx/crashfx.wav");
	Sound_win = App->audio->LoadFx("Game/Fx/SoundWin.wav");


	
	float road_width = 12.0f;
	float road_height = 3.0f;
	fallen = false;
	fallen2 = false;
	sen_1 = false;
	sen_2 = false;
	sen_3 = false;
	sen_4 = false;
	sen2_1 = false;
	sen2_2 = false;
	sen2_3 = false;
	sen2_4 = true;
	
	sensor_floor = { 1000,1,2000 };
	sensor_form = { road_width, road_height * 3, 1 };
	sensor_form2 = { 1, road_height * 3, road_width };
	c[1].size.Set(road_width, road_height, 150);
	c[1].SetPos(0, 27, 30);
	App->physics->AddBody(c[1], 0)->collision_listeners.add(this);
	
	//Ramp 1 - UP
	for (n = 0; n<80; ++n)
	{
		c[n].color = Grey;
	}

	c[2].size.Set(road_width, road_height, 15);
	c[2].SetPos(0, 28.3, 112.5);
	c[2].SetRotation(10, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[2], 0);
	
	c[3].size.Set(road_width, road_height, 15);
	c[3].SetPos(0, 32.2, 127);
	c[3].SetRotation(20, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[3], 0);

	c[4].size.Set(road_width, road_height, 60);
	c[4].SetPos(0, 49.9, 160.3);
	c[4].SetRotation(30, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[4], 0);

	c[5].size.Set(road_width, road_height, 15);
	c[5].SetPos(0, 67.3, 193);
	c[5].SetRotation(200, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[5], 0);

	c[6].size.Set(road_width, road_height, 15);
	c[6].SetPos(0,71.1, 207.3);
	c[6].SetRotation(190, vec3(-1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[6], 0);

	c[7].size.Set(road_width, road_height, 80);
	c[7].SetPos(0, 72.35, 254.4);
	App->physics->AddBody(c[7], 0);
	
	//Ramp 2 - Down

	c[8].size.Set(road_width, road_height, 15);
	c[8].SetPos(0, 28.3, 395.6);
	c[8].SetRotation(10, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[8], 0);

	c[9].size.Set(road_width, road_height, 60);
	c[9].SetPos(0, 49.9, 347.8);
	c[9].SetRotation(30, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[9], 0);

	c[10].size.Set(road_width, road_height, 15);
	c[10].SetPos(0, 32.2,381.1);
	c[10].SetRotation(20, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[10], 0);

	c[11].size.Set(road_width, road_height, 15);
	c[11].SetPos(0, 67.3, 315.1);
	c[11].SetRotation(20, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[11], 0);

	c[12].size.Set(road_width, road_height, 15);
	c[12].SetPos(0, 71.1, 301);
	c[12].SetRotation(10, vec3(1.0f, 0.0f, 0.0f));
	App->physics->AddBody(c[12], 0);

	c[13].size.Set(road_width, road_height, 150);
	c[13].SetPos(0,27, 478);
	App->physics->AddBody(c[13], 0);

	//Curve

	c[14].size.Set(road_width, road_height, 20);
	c[14].SetPos(0.9, 27, 562);
	c[14].SetRotation(5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[14], 0);

	c[15].size.Set(road_width, road_height, 20);
	c[15].SetPos(3.4, 27, 581);
	c[15].SetRotation(10, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[15], 0);
	
	c[16].size.Set(road_width, road_height, 20);
	c[16].SetPos(7.6, 27, 600);
	c[16].SetRotation(15, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[16], 0);
	
	c[17].size.Set(road_width, road_height, 20);
	c[17].SetPos(13.3, 27, 618);
	c[17].SetRotation(20, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[17], 0);
	
	c[18].size.Set(road_width, road_height, 20);
	c[18].SetPos(20.8, 27, 636);
	c[18].SetRotation(25, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[18], 0);

	c[19].size.Set(road_width, road_height, 20);
	c[19].SetPos(29.7, 27, 653);
	c[19].SetRotation(30, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[19], 0);

	c[20].size.Set(road_width, road_height, 20);
	c[20].SetPos(39.95, 27, 669);
	c[20].SetRotation(35, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[20], 0);
	
	c[21].size.Set(road_width, road_height, 20);
	c[21].SetPos(50.8, 27, 683);
	c[21].SetRotation(40, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[21], 0);

	c[22].size.Set(road_width, road_height, 150);
	c[22].SetPos(109.7, 27, 743);
	c[22].SetRotation(45, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[22], 0);

	c[23].size.Set(road_width, road_height, 30);
	c[23].SetPos(174.9, 27, 800.3);
	c[23].SetRotation(67.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[23], 0);

	c[24].size.Set(road_width, road_height, 30);
	c[24].SetPos(201.5, 27, 805.5);
	c[24].SetRotation(90, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[24], 0);
	
	c[25].size.Set(60, road_height, road_width);
	c[25].SetPos(268, 27, 806.5);
	App->physics->AddBody(c[25], 0);

	c[26].size.Set(road_width, road_height, 10);
	c[26].SetPos(201.5, 27, 805.5);
	c[26].SetRotation(7.5, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[26], 0);

	c[27].size.Set(road_width, road_height, 10);
	c[27].SetPos(213, 29.3, 805.5);
	c[27].SetRotation(15, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[27], 0);
	//
	
	c[28].size.Set(road_width, road_height, 15);
	c[28].SetPos(302.7, 27, 804.1);
	c[28].SetRotation(112.5, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[28], 0);
	
	c[29].size.Set(road_width, road_height, 15);
	c[29].SetPos(312, 27, 798);
	c[29].SetRotation(135, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[29], 0);
	
	c[30].size.Set(road_width, road_height, 18);
	c[30].SetPos(318.7, 27, 787.7);
	c[30].SetRotation(157.5, vec3(0.0f, 1.0f, -0.0f));
	App->physics->AddBody(c[30], 0);
	
	c[50].size.Set(road_width, road_height, 60);
	c[50].SetPos(321.7, 27, 752);
	c[50].SetRotation(180, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[50], 0);
	
	c[31].size.Set(50, road_height, road_width*2/3);
	c[31].SetPos(302, 27, 726.07);
	App->physics->AddBody(c[31], 0);

	c[32].size.Set(road_width * 2 / 3, road_height, 50);
	c[32].SetPos(278, 27, 705.09);
	App->physics->AddBody(c[32], 0);
	//
	c[33].size.Set(50, road_height, road_width * 2 / 3);
	c[33].SetPos(255, 27, 684);
	App->physics->AddBody(c[33], 0);

	c[34].size.Set(50, road_height, road_width * 2 / 3);
	c[34].SetPos(205, 27, 727.42);
	App->physics->AddBody(c[34], 0);

	c[35].size.Set(road_width * 2 / 3, road_height, 50);
	c[35].SetPos(226, 27, 705.09);
	App->physics->AddBody(c[35], 0);

	c[36].size.Set(road_width * 2 / 3, road_height, 50);
	c[36].SetPos(184, 27, 700.34);
	App->physics->AddBody(c[36], 0);

	//Pieces with movement.

	c[37].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[37].SetPos(184, 27, 671.3);
	App->physics->AddBody(c[37], 0);

	c[38].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[38].SetPos(184, 27, 663.25);
	App->physics->AddBody(c[38], 0);

	c[39].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[39].SetPos(184, 27, 655.2);
	App->physics->AddBody(c[39], 0);

	c[40].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[40].SetPos(184, 27, 647.15);
	App->physics->AddBody(c[40], 0);

	c[41].size.Set(road_width * 2 / 3, road_height, road_width * 2 / 3);
	c[41].SetPos(184, 27, 639.1);
	App->physics->AddBody(c[41], 0);

	//Curve for d
	c[52].size.Set(road_width , road_height,350);
	c[52].SetPos(184, 27, 460);
	App->physics->AddBody(c[52], 0);

	c[53].size.Set(road_width, road_height, 15);
	c[53].SetPos(182, 27, 282.95);
	c[53].SetRotation(18, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[53], 0);

	c[54].size.Set(road_width, road_height, 15);
	c[54].SetPos(176.15, 27, 271.45);
	c[54].SetRotation(36, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[54], 0);

	c[55].size.Set(road_width, road_height, 15);
	c[55].SetPos(167, 27, 262.35);
	c[55].SetRotation(54, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[55], 0);

	c[56].size.Set(road_width, road_height, 15);
	c[56].SetPos(155.5, 27 , 256.45);
	c[56].SetRotation(72, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[56], 0);

	c[51].size.Set(50, road_height, road_width);
	c[51].SetPos(125.2, 27, 254.4);
	App->physics->AddBody(c[51], 0);

	//Up PF

	c[57].size.Set(7.5, road_height, road_width);
	c[57].SetPos(97, 27.6, 254.4);
	c[57].SetRotation(11.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[57], 0);

	c[58].size.Set(7.5, road_height, road_width);
	c[58].SetPos(89.7, 29.8, 254.4);
	c[58].SetRotation(22.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[58], 0);

	c[59].size.Set(30, road_height, road_width);
	c[59].SetPos(73.5, 39.7, 254.4);
	c[59].SetRotation(33.75, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[59], 0);

	c[60].size.Set(7.5, road_height, road_width);
	c[60].SetPos(57.8, 49.32, 254.4);
	c[60].SetRotation(22.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[60], 0);

	c[0].size.Set(7.5, road_height, road_width);
	c[0].SetPos(0, 15, 254.4);
	c[0].SetRotation(0, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[0], 0);
	
	c[61].size.Set(7.5, road_height, road_width);
	c[61].SetPos(50.9, 51.4, 254.4);
	c[61].SetRotation(11.25, vec3(0.0f, 0.0f, -1.0f));
	App->physics->AddBody(c[61], 0);

	c[62].size.Set(15, road_height, road_width);
	c[62].SetPos(40, 52.1, 254.4);
	App->physics->AddBody(c[62], 0);

	//DownPF
	c[63].size.Set(7.5, road_height, road_width);
	c[63].SetPos(22.2, 49.32, 254.4);
	c[63].SetRotation(22.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[63], 0);

	c[64].size.Set(7.5, road_height, road_width);
	c[64].SetPos(29.1, 51.4, 254.4);
	c[64].SetRotation(11.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[64], 0);
	//LineD
	c[65].size.Set(40, road_height, road_width);
	c[65].SetPos(2.4, 36.94, 254.4);
	c[65].SetRotation(33.75, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[65], 0);

	//DPF
	c[66].size.Set(35, road_height, road_width);
	c[66].SetPos(-22.55, 20.27, 254.4);
	c[66].SetRotation(33.75, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[66], 0);

	c[67].size.Set(7.5, road_height, road_width);
	c[67].SetPos(-38.85, 10.3, 254.4);
	c[67].SetRotation(22.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[67], 0);
	
	c[68].size.Set(7.5, road_height, road_width);
	c[68].SetPos(-46.25, 8.05, 254.4);
	c[68].SetRotation(11.25, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[68], 0);

	//Down
	c[43].size.Set(120, road_height, road_width);
	c[43].SetPos(-100, 7.3, 254.4);
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
	c[47].SetPos(-34.7, 17.26 , -37.5);
	c[47].SetRotation(30, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[47], 0);

	c[48].size.Set(road_width, road_height, 15);
	c[48].SetPos(-22.8, 22.95, -37.5);
	c[48].SetRotation(200, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[48], 0);

	c[49].size.Set(road_width, road_height, 15);
	c[49].SetPos(-11.5, 26,-37.5);
	c[49].SetRotation(190, vec3(0.0f, 0.0f, 1.0f));
	App->physics->AddBody(c[49], 0);
	
	/////// Curve final ramp182
	
	c[69].size.Set(road_width, road_height, 15);
	c[69].SetPos(-129.5, 7.3, -35.5);
	c[69].SetRotation(108, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[69], 0);

	c[70].size.Set(road_width, road_height, 15);
	c[70].SetPos(-140.9, 7.3, -29.7);
	c[70].SetRotation(126, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[70], 0);

	c[71].size.Set(road_width, road_height, 15);
	c[71].SetPos(-150, 7.3, -20.5);
	c[71].SetRotation(144, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[71], 0);

	c[72].size.Set(road_width, road_height, 15);
	c[72].SetPos(-155.8, 7.3, -9);
	c[72].SetRotation(162, vec3(0.0f, 1.0f, 0.0f));
	App->physics->AddBody(c[72], 0);

	c[73].size.Set(road_width, road_height, 270);
	c[73].SetPos(-159, 7.3, 125);
	App->physics->AddBody(c[73], 0);

	//Sensor
	sensor_flo = App->physics->AddBody(sensor_floor, 0.0f);
	sensor_flo->SetAsSensor(true);
	sensor_flo->SetPos(0, 0, 0);
	sensor_flo->GetTransform(&sensor_floor.transform);
	sensor_flo->collision_listeners.add(this);

	sensor_1 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_1->SetAsSensor(true);
	sensor_1->SetPos(0.9, 12 + 15, 562);
	sensor_1->GetTransform(&sensor_form.transform);
	sensor_1->collision_listeners.add(this);

	sensor_2 = App->physics->AddBody(sensor_form2, 0.0f);
	sensor_2->SetAsSensor(true);
	sensor_2->SetPos(302, 27, 726.07);
	sensor_2->GetTransform(&sensor_form2.transform);
	sensor_2->collision_listeners.add(this);

	sensor_3 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_3->SetAsSensor(true);
	sensor_3->SetPos(184, 27, 671.3);
	sensor_3->GetTransform(&sensor_form.transform);
	sensor_3->collision_listeners.add(this);

	sensor_4 = App->physics->AddBody(sensor_form2, 0.0f);
	sensor_4->SetAsSensor(true);
	sensor_4->SetPos(125.2, 27, 254.4);
	sensor_4->GetTransform(&sensor_form2.transform);
	sensor_4->collision_listeners.add(this);
	//	//x=0,	y=56.1,	z=193	2, 27, 30*/
	return ret;
}
void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	if (body1 == sensor_flo && body2 == App->player->vehicle)
	{
		
		fallen = true;
		Crash_fx = App->audio->LoadFx("Game/Fx/crashfx.wav");
		LOG("HIT!");
	}
	if (body1 == sensor_1 && body2 == App->player->vehicle)
	{
		sen_1 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_2 && body2 == App->player->vehicle && sen_1 == true)
	{
		sen_2 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_3 && body2 == App->player->vehicle && sen_2 == true)
	{
		sen_3 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_4 && body2 == App->player->vehicle && sen_3 == true)
	{
		sen_4 = true;
		LOG("HIT!");
	}
	///2nd player
	if (body1 == sensor_flo && body2 == App->player2->vehicle2)
	{
		Crash_fx = App->audio->LoadFx("Game/Fx/crashfx.wav");
		fallen2 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_1 && body2 == App->player2->vehicle2)
	{
		sen2_1 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_2 && body2 == App->player2->vehicle2 && sen2_1 == true)
	{
		sen2_2 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_3 && body2 == App->player2->vehicle2 && sen2_2 == true)
	{
		sen2_3 = true;
		LOG("HIT!");
	}
	if (body1 == sensor_4 && body2 == App->player2->vehicle2 && sen2_3 == true)
	{
		sen2_4 = true;
		LOG("HIT!");
	}
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
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();*/
	for (n = 0; n<80; ++n)
	{
		c[n].Render();
	}
	
	
	return UPDATE_CONTINUE;
}


