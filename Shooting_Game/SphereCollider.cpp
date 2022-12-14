#include "SphereCollider.h"
#include <math.h>
#define _USE_MATH_DEFINES

bool SphereCollider::HitSphere(VECTOR bullets, float Bradius)
{
	float xlength = bullets.x - location.x;   //２点間のx軸の長さ
	float ylength = bullets.y - location.y;   //２点間のy軸の長さ
	float length = static_cast<float>(sqrt(pow(xlength, 2) + pow(ylength, 2)));

	if (length <= Bradius+radius)
	{
		return true;
	}
	return false;
}