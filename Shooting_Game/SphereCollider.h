#pragma once
#include "DxLib.h"
class SphereCollider
{
public:
	bool HitSphere(VECTOR bullets, float Bradius);
	VECTOR GetLocation()const { return location; }
	float GetRadius()const { return radius; }
	void SetLocation(VECTOR location) { this->location = location; }

protected:
	VECTOR location;     //’†SÀ•W
	float radius;       //”¼Œa
};

