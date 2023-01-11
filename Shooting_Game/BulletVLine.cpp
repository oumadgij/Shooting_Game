#include "BulletVLine.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>

BulletVLine::BulletVLine(float x, float y, float sp, float r, int angle)
{
	location.x = x;
	location.y = y;
	location.z = 0;
	speed = sp;
	radius = r;
	damage = 1;
	image = 0;
	this->angle = angle;
}

void BulletVLine::Update()
{
	location.x += cos(angle * M_PI / 180.0) * speed;
	location.y += sin(angle * M_PI / 180.0) * speed;
}

void BulletVLine::Draw()const
{

}