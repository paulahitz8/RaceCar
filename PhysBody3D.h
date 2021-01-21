#ifndef __PhysBody3D_H__
#define __PhysBody3D_H__

#include "p2List.h"

class btRigidBody;
class Module;
class btVector3;

// =================================================
struct PhysBody3D
{
	friend class ModulePhysics3D;
	enum class Tag { PLAYER, CHECKPOINT, FINISH, NONE };
public:
	PhysBody3D(btRigidBody* body);
	~PhysBody3D();

	void Push(float x, float y, float z);
	void GetTransform(float* matrix) const;
	void SetAsSensor(bool is_sensor);
	void SetTag(Tag currentTag);
	Tag GetTag();
	void SetActive(bool active);
	void SetTransform(const float* matrix) const;
	void SetPos(float x, float y, float z);
	btRigidBody* GetBody();

private:
	btRigidBody* body = nullptr;
	bool is_sensor = false;
	Tag tag;
	bool active = true;

public:
	p2List<Module*> collision_listeners;
	bool onCollision = true;
};

#endif // __PhysBody3D_H__