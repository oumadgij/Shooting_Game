#include "SphereCollider.h"
#include <math.h>
#define _USE_MATH_DEFINES

//bool SphereCollider::HitSphere(VECTOR bullets, VECTOR chara,int bullet_r, int chara_r)
//{
//	float xlength = bullets.x - chara.x;   //‚Q“_ŠÔ‚ÌxŽ²‚Ì’·‚³
//	float ylength = bullets.y - chara.y;   //‚Q“_ŠÔ‚ÌyŽ²‚Ì’·‚³
//	float length = sqrt(pow(xlength, 2) + pow(ylength, 2));
//
//	if (length <= bullet_r + chara_r)
//	{
//		return true;
//	}
//	return false;
//}

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