#pragma once
#include "BulletsBase.h"

class BulletStraight :public BulletsBase
{
public:
	BulletStraight(float x, float y,float speed,float r);
	//~BulletStraight();
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•
	void Update()override;
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•
	void Draw()const override;

private:
};

