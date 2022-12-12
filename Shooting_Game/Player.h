#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#include "ItemBase.h"

class Player : public CharaBase,public SphereCollider
{
public:
	//コンストラクタ
	Player();
	//描画以外の更新を実装
	virtual void Update()override;
	//描画に関することを実装
	virtual void Draw()const override;
	//当たり判定
	virtual void Hit(int damage)override;
	void Hit(ITEM_TYPE item,int effects);
	void LifeCheck();
	void DeleteBullet(int bulletcount);
	int GetScore()const { return score; }

private:
	int x, y;
	int score;   //スコア
	int life;    //HP
	int shotCount;
	int upDamage;
};

