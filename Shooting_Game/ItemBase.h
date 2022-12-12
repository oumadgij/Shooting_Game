#pragma once
#include "SphereCollider.h"

enum class ITEM_TYPE
{
	HEAL = 0,   //HP回復
	ATTACK,     //攻撃力アップ
	DEFAULT
};

enum class ITEM_EFFECTS
{
	HEAL = 10,  //回復量
	ATTACK = 3, //上がる攻撃力
	DEFAULT
};

class ItemBase:public SphereCollider
{
public:
	//コンストラクタ
	ItemBase();
	//デストラクタ
	virtual ~ItemBase() {};
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	ITEM_TYPE GetType()const { return type; }
	ITEM_EFFECTS GetEffects()const { return effects; }

protected:
	float speed;
	ITEM_TYPE type;
	ITEM_EFFECTS effects;
};