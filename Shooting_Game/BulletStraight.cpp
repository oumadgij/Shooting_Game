#include "BulletStraight.h"

BulletStraight::BulletStraight(float x, float y)
{
	Vbullet.x = x;
	Vbullet.y = y;
	speed = 8.f;
}

void BulletStraight::Update()
{
	Vbullet.y -= speed;
}

void BulletStraight::Draw()const
{
	DrawCircle(Vbullet.x, Vbullet.y, 5, GetColor(100, 180, 0), TRUE);
}