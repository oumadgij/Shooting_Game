#pragma once
class SphereCollider
{
public:
	void HitSphere();
	int GetLocation()const { return location; }
	void SetLocation(int location) { this->location = location; }

private:
	int location;     //���S���W
	int radius;       //���a
};

