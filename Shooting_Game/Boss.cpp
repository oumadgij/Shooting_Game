#include "Boss.h"

Boss::Boss(float Vx, float Vy, float r)
{
	hp = 10;
	radius = r;
	point = 0;
	speed = 0.5f;
	location.x = Vx;
	location.y = Vy;
	shotCount = 0;
}

void Boss::Update()
{

}

void Boss::Draw()const
{
	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x4b0082, TRUE);
}

void Boss::Hit(int damage)
{

}