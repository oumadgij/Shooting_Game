#pragma once
#include "SphereCollider.h"

class BulletsBase :public SphereCollider
{
public:
	//コンストラクタ
	BulletsBase();
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }
	void UpDamage(int damage) { this->damage += damage; }

protected:
	int damage;   //ダメージ
	float speed;    //スピード
	int image;
};