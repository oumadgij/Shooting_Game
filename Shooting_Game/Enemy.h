#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Enemy : public CharaBase, public SphereCollider
{
public:
	//コンストラクタ
	Enemy(float x,float y);
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
	int shotCount;
};

