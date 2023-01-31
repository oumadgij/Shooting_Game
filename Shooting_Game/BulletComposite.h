#pragma once
#include "BulletsBase.h"
class BulletComposite :public BulletsBase
{
public:
	//コンストラクタ
	BulletComposite(float x, float y, float sp, float r, int angle, int updamage);
	//描画以外の更新を実装
	void Update()override;
	//描画に関することを実装
	void Draw()const override;
private:
	int angle;
};