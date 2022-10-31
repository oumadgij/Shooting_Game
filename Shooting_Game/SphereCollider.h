#pragma once
class SphereCollider
{
public:
	void HitSphere();
	int GetLocation()const { return location; }
	void SetLocation(int location) { this->location = location; }

protected:
	int location;     //’†SÀ•W
	int radius;       //”¼Œa
};

