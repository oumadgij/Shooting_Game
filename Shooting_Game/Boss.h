#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

class Boss :public CharaBase,public SphereCollider
{
public:
	//コンストラクタ
	Boss(float Vx, float Vy, float r);  //(x座標,y座標,半径)
	//描画以外の更新を実装
	virtual void Update() override;
	//描画に関することを実装
	virtual void Draw() const override;
	//当たり判定
	virtual void Hit(int damage) override;

private:
	int hp;
	int point;
	int shotCount;
};

