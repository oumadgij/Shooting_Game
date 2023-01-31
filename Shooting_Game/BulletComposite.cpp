#include "BulletComposite.h"
#define _USE_MATH_DEFINES
#include <math.h>

BulletComposite::BulletComposite(float x, float y, float sp, float r, int angle, int updamage)
{
	location.x = x;
	location.y = y;
	location.z = 0;
	speed = sp;
	radius = r;
	damage = 1;
	damage += updamage;
	this->angle = angle;
}

void BulletComposite::Update()
{
	location.x += cos(angle * M_PI / 180.0) * speed;
	location.y += sin(angle * M_PI / 180.0) * speed;
}

void BulletComposite::Draw()const
{

}