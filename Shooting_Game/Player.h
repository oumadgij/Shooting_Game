#pragma once
#include "CharaBase.h"
#include "BulletsBase.h"
class Player : public CharaBase,public BulletsBase
{
public:
	//描画以外の更新を実装
	void Update()override;
	//描画に関することを実装
	void Draw()const override;
	//当たり判定
	void Hit()override;
	void LifeCheck();
	int GetScore()const { return score; }

private:
	int x, y;    //X座標,Y座標
	int score;   //スコア
	int life;    //HP
};

