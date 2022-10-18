#pragma once
#include "SphereCollider.h"

class BulletsBase : public SphereCollider
{
public:
	//コンストラクタ
	BulletsBase();
	//デストラクタ
	virtual ~BulletsBase() {};
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }

protected:
	int damage;   //ダメージ
	int speed;    //スピード
	int x, y;     //X座標,Y座標
};