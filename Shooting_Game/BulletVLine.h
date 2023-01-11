#pragma once
#include "BulletsBase.h"
class BulletVLine : public BulletsBase
{
public:
	//コンストラクタ
	BulletVLine(float x, float y, float sp, float r, int angle);
	//描画以外の更新を実装
	void Update()override;
	//描画に関することを実装
	void Draw()const override;

private:
	int angle;
};

