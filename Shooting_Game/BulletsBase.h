#pragma once
#include "SphereCollider.h"
#include "DxLib.h"

class BulletsBase :public SphereCollider
{
public:
	//コンストラクタ
	/*BulletsBase(float x, float y);*/
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }
	float GetBulletY()const { return Vbullet.y; }

protected:
	int damage;   //ダメージ
	float speed;    //スピード
	int image;
	VECTOR Vbullet;
};