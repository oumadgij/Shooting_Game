#pragma once
#include "SphereCollider.h"

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

protected:
	float speed;
};