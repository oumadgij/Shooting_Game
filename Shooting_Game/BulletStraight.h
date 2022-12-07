#pragma once
#include "BulletsBase.h"

class BulletStraight :public BulletsBase
{
public:
	BulletStraight(float x, float y,float speed,float r);
	//~BulletStraight();
	//描画以外の更新を実装
	void Update()override;
	//描画に関することを実装
	void Draw()const override;

private:
};

