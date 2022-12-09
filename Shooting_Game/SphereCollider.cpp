#include "SphereCollider.h"
#include <math.h>
#define _USE_MATH_DEFINES

bool SphereCollider::HitSphere(VECTOR bullets, float Bradius)
{
	float xlength = bullets.x - location.x;   //‚Q“_ŠÔ‚ÌxŽ²‚Ì’·‚³
	float ylength = bullets.y - location.y;   //‚Q“_ŠÔ‚ÌyŽ²‚Ì’·‚³
	float length = static_cast<float>(sqrt(pow(xlength, 2) + pow(ylength, 2)));

	if (length <= Bradius+radius)
	{
		return true;
	}
	return false;
}