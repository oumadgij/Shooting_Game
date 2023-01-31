#pragma once
#include "ItemBase.h"

enum class ITEM_TYPE
{
	HEAL = 0,   //HP回復
	ATTACK,     //攻撃力アップ
	DEFAULT
};

enum class ITEM_EFFECTS
{
	HEAL = 2,  //回復量
	ATTACK = 1, //上がる攻撃力
	DEFAULT
};

class DropItem :public ItemBase
{
public:
	DropItem(VECTOR location, float radius, int type, float speed);
	//描画以外の更新を実装
	virtual void Update()override;
	//描画に関することを実装
	virtual void Draw()const override;
	ITEM_TYPE GetType()const { return type; }
	ITEM_EFFECTS GetEffects()const { return effects; }

private:
	ITEM_TYPE type;
	ITEM_EFFECTS effects;
};

