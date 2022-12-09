#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Enemy : public CharaBase, public SphereCollider
{
public:
	//コンストラクタ
	Enemy(float Vx,float Vy,float r);  //(x座標,y座標,半径)
	//描画以外の更新を実装
	virtual void Update() override;
	//描画に関することを実装
	virtual void Draw() const override;
	//当たり判定
	virtual void Hit(int damage) override;
	//Hpが0か
	bool HpCheck();
	int GetPoint()const { return point; }
	int GetHP()const { return hp; }
	void DeleteBullet(int bulletcount);

private:
	int hp;
	int point;
	int shotCount;
};

