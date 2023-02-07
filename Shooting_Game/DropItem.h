#pragma once
#include "ItemBase.h"

enum class ITEM_TYPE
{
	HEAL = 0,   //HP回復
	ATTACK,     //攻撃力アップ
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
	int GetEffects(int t)const { return effects[t]; }

private:
	const int effects[3] = { 2,1,0 };  //効果 0列目:回復量 1列目:上がる攻撃量 2列目:なにもなし
	ITEM_TYPE type;  //アイテムタイプ
};

