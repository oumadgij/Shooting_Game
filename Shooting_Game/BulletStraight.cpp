#include "BulletStraight.h"

BulletStraight::BulletStraight(float x, float y,float sp)
{
	Vbullet.x = x;
	Vbullet.y = y;
	Vbullet.z = 0;
	speed = sp;
	damage = 0;
	image = 0;
}

void BulletStraight::Update()
{
	Vbullet.y += speed;
}

void BulletStraight::Draw()const
{
	DrawCircle(static_cast<int>(Vbullet.x), static_cast<int>(Vbullet.y), 5, GetColor(100, 180, 0), TRUE);
}