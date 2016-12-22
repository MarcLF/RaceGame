#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Red;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	chassis.color = Mate;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	chassis.Render();

	Cube Aileron2(info.chassis_size.x*0.05f, info.chassis_size.y*0.3f, info.chassis_size.z*0.02f);
	Aileron2.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Aileron2.transform);
	btQuaternion q2 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset2(info.chassis_offset.x-0.7, info.chassis_offset.y+0.5, info.chassis_offset.z - 1.9f);
	offset2 = offset2.rotate(q2.getAxis(), q2.getAngle());

	Aileron2.transform.M[12] += offset2.getX();
	Aileron2.transform.M[13] += offset2.getY();
	Aileron2.transform.M[14] += offset2.getZ();

	Aileron2.Render();

	Cube Aileron1(info.chassis_size.x*0.05f, info.chassis_size.y*0.3f, info.chassis_size.z*0.02f);
	Aileron1.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Aileron1.transform);
	btQuaternion q3 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset3(info.chassis_offset.x + 0.7, info.chassis_offset.y + 0.5, info.chassis_offset.z - 1.9f);
	offset3 = offset3.rotate(q3.getAxis(), q3.getAngle());

	Aileron1.transform.M[12] += offset3.getX();
	Aileron1.transform.M[13] += offset3.getY();
	Aileron1.transform.M[14] += offset3.getZ();

	Aileron1.Render();

	Cube Aileron(info.chassis_size.x*1.0f, info.chassis_size.y*0.02f, info.chassis_size.z*0.1f);
	Aileron.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Aileron.transform);
	btQuaternion q4 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset4(info.chassis_offset.x , info.chassis_offset.y + 0.7, info.chassis_offset.z - 1.9f);
	offset4 = offset4.rotate(q4.getAxis(), q4.getAngle());

	Aileron.transform.M[12] += offset4.getX();
	Aileron.transform.M[13] += offset4.getY();
	Aileron.transform.M[14] += offset4.getZ();

	Aileron.Render();

	Cube Pipe(info.chassis_size.x*1.0f, info.chassis_size.y*0.3f, info.chassis_size.z*0.1f);
	Pipe.color = Red;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Pipe.transform);
	btQuaternion q5 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset5(info.chassis_offset.x, info.chassis_offset.y -0.4, info.chassis_offset.z +1.9 );
	offset5 = offset5.rotate(q5.getAxis(), q5.getAngle());

	Pipe.transform.M[12] += offset5.getX();
	Pipe.transform.M[13] += offset5.getY();
	Pipe.transform.M[14] += offset5.getZ();

	Pipe.Render();



}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}

// Player 2

VehicleInfoP2::~VehicleInfoP2()
{
	//if(wheels != NULL)
	//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3DP2::PhysVehicle3DP2(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3DP2::~PhysVehicle3DP2()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3DP2::Render()
{
	Cylinder wheel;

	wheel.color = Blue;

	for (int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	chassis.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	chassis.Render();

	Cube Aileron2(info.chassis_size.x*0.05f, info.chassis_size.y*0.3f, info.chassis_size.z*0.02f);
	Aileron2.color = Blue;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Aileron2.transform);
	btQuaternion q2 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset2(info.chassis_offset.x - 0.7, info.chassis_offset.y + 0.5, info.chassis_offset.z - 1.9f);
	offset2 = offset2.rotate(q2.getAxis(), q2.getAngle());

	Aileron2.transform.M[12] += offset2.getX();
	Aileron2.transform.M[13] += offset2.getY();
	Aileron2.transform.M[14] += offset2.getZ();

	Aileron2.Render();

	Cube Aileron1(info.chassis_size.x*0.05f, info.chassis_size.y*0.3f, info.chassis_size.z*0.02f);
	Aileron1.color = Blue;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Aileron1.transform);
	btQuaternion q3 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset3(info.chassis_offset.x + 0.7, info.chassis_offset.y + 0.5, info.chassis_offset.z - 1.9f);
	offset3 = offset3.rotate(q3.getAxis(), q3.getAngle());

	Aileron1.transform.M[12] += offset3.getX();
	Aileron1.transform.M[13] += offset3.getY();
	Aileron1.transform.M[14] += offset3.getZ();

	Aileron1.Render();

	Cube Aileron(info.chassis_size.x*1.0f, info.chassis_size.y*0.02f, info.chassis_size.z*0.1f);
	Aileron.color = Blue;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Aileron.transform);
	btQuaternion q4 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset4(info.chassis_offset.x, info.chassis_offset.y + 0.7, info.chassis_offset.z - 1.9f);
	offset4 = offset4.rotate(q4.getAxis(), q4.getAngle());

	Aileron.transform.M[12] += offset4.getX();
	Aileron.transform.M[13] += offset4.getY();
	Aileron.transform.M[14] += offset4.getZ();

	Aileron.Render();

	Cube Pipe(info.chassis_size.x*1.0f, info.chassis_size.y*0.3f, info.chassis_size.z*0.1f);
	Pipe.color = Blue;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&Pipe.transform);
	btQuaternion q5 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset5(info.chassis_offset.x, info.chassis_offset.y - 0.4, info.chassis_offset.z + 1.9);
	offset5 = offset5.rotate(q5.getAxis(), q5.getAngle());

	Pipe.transform.M[12] += offset5.getX();
	Pipe.transform.M[13] += offset5.getY();
	Pipe.transform.M[14] += offset5.getZ();

	Pipe.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3DP2::ApplyEngineForce(float force)
{
	for (int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if (info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3DP2::Brake(float force)
{
	for (int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if (info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3DP2::Turn(float degrees)
{
	for (int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if (info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3DP2::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}
