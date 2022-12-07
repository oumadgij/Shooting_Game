#include "BulletStraight.h"

BulletStraight::BulletStraight(float x, float y,float sp,float r)
{
	location.x = x;
	location.y = y;
	location.z = 0;
	speed = sp;
	radius = r;
	damage = 1;
	image = 0;
}

void BulletStraight::Update()
{
	location.y += speed;
}

void BulletStraight::Draw()const
{
	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(100, 180, 0), TRUE);
}