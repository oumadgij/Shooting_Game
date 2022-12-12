#include "BulletStraight.h"

BulletStraight::BulletStraight(float x, float y,float sp,float r,int updamage)
{
	location.x = x;
	location.y = y;
	location.z = 0;
	speed = sp;
	radius = r;
	damage = 1;
	damage += updamage;
	image = 0;
}

void BulletStraight::Update()
{
	location.y += speed;
}

void BulletStraight::Draw()const
{
}