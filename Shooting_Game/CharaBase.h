#pragma once
#include "BulletsBase.h"
#include "DxLib.h"
class CharaBase
{
public:
	//コンストラクタ
	CharaBase();
	//デストラクタ
	virtual ~CharaBase() {};
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	//当たり判定
	virtual void Hit(int damage) = 0;

	BulletsBase** GetBullets()const { return bullets; }
	
protected:
	int image;
	float speed;
	BulletsBase** bullets;  //弾　仮置き TO DO
};