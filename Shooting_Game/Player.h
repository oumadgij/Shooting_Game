#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

class Player : public CharaBase,public SphereCollider
{
public:
	//コンストラクタ
	Player();
	//Player(int x, int y, int score, int life);
	//描画以外の更新を実装
	virtual void Update()override;
	//描画に関することを実装
	virtual void Draw()const override;
	//当たり判定
	virtual void Hit()override;
	void LifeCheck();
	int GetScore()const { return score; }

private:
	int x, y;
	int score;   //スコア
	int life;    //HP
};

