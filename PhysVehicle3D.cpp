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

	wheel.color = DarkPurple;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassisFront(info.chassisFront_size.x, info.chassisFront_size.y, info.chassisFront_size.z);
	chassisFront.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassisFront.transform);
	btQuaternion qFront = vehicle->getChassisWorldTransform().getRotation();
	btVector3 frontOffset(info.chassisFront_offset.x, info.chassisFront_offset.y, info.chassisFront_offset.z);
	frontOffset = frontOffset.rotate(qFront.getAxis(), qFront.getAngle());
	chassisFront.transform.M[12] += frontOffset.getX();
	chassisFront.transform.M[13] += frontOffset.getY();
	chassisFront.transform.M[14] += frontOffset.getZ();

	Cube chassisBack(info.chassisBack_size.x, info.chassisBack_size.y, info.chassisBack_size.z);
	chassisBack.color = White;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassisBack.transform);
	btQuaternion qBack = vehicle->getChassisWorldTransform().getRotation();
	btVector3 backOffset(info.chassisBack_offset.x, info.chassisBack_offset.y, info.chassisBack_offset.z);
	backOffset = backOffset.rotate(qBack.getAxis(), qBack.getAngle());
	chassisBack.transform.M[12] += backOffset.getX();
	chassisBack.transform.M[13] += backOffset.getY();
	chassisBack.transform.M[14] += backOffset.getZ();

	Cube chassisLight1(info.chassisLight1_size.x, info.chassisLight1_size.y, info.chassisLight1_size.z);
	chassisLight1.color = DarkPurple;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassisLight1.transform);
	btQuaternion qLight1 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 light1Offset(info.chassisLight1_offset.x, info.chassisLight1_offset.y, info.chassisLight1_offset.z);
	light1Offset = light1Offset.rotate(qLight1.getAxis(), qLight1.getAngle());
	chassisLight1.transform.M[12] += light1Offset.getX();
	chassisLight1.transform.M[13] += light1Offset.getY();
	chassisLight1.transform.M[14] += light1Offset.getZ();

	Cube chassisLight2(info.chassisLight2_size.x, info.chassisLight2_size.y, info.chassisLight2_size.z);
	chassisLight2.color = DarkPurple;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassisLight2.transform);
	btQuaternion qLight2 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 light2Offset(info.chassisLight2_offset.x, info.chassisLight2_offset.y, info.chassisLight2_offset.z);
	light2Offset = light2Offset.rotate(qLight2.getAxis(), qLight2.getAngle());
	chassisLight2.transform.M[12] += light2Offset.getX();
	chassisLight2.transform.M[13] += light2Offset.getY();
	chassisLight2.transform.M[14] += light2Offset.getZ();

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();


	chassis.Render();
	chassisFront.Render();
	chassisBack.Render();
	chassisLight1.Render();
	chassisLight2.Render();
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