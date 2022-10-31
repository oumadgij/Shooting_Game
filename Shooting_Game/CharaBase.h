#pragma once
#include "BulletsBase.h"
class CharaBase :public BulletsBase
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
	virtual void Hit() = 0;

	CharaBase* GetBullets(int bullet)const { return this->bullets[bullet]; }
	
protected:
	int image;
	CharaBase* bullets[30];  //弾　仮置き TO DO
	int speed;
};