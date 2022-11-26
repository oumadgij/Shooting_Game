#include "BulletStraight.h"

BulletStraight::BulletStraight(float x, float y)
{
	Vbullet.x = x;
	Vbullet.y = y;
	Vbullet.z = 0;
	speed = 8.f;
	damage = 0;
	image = 0;
}

void BulletStraight::Update()
{
	Vbullet.y -= speed;
}

void BulletStraight::Draw()const
{
	DrawCircle(Vbullet.x, Vbullet.y, 5, GetColor(100, 180, 0), TRUE);
}