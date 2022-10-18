#pragma once
#include "CharaBase.h"
#include "BulletsBase.h"
class Enemy : public CharaBase, public BulletsBase
{
public:
	//コンストラクタ
	Enemy();
	//描画以外の更新を実装
	virtual void Update() override;
	//描画に関することを実装
	virtual void Draw() const override;
	//当たり判定
	virtual void Hit() override;
	//Hpが0か
	void HpCheck();
	int GetPoint()const { return point; }

private:
	int hp;
	int point;
};

