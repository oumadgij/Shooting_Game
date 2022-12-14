#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"
class GameMain : public AbstractScene
{
public:
	//コンストラクタ
	GameMain();
	//デストラクタ
	~GameMain() 
	{ 
		delete player; 
		delete enemy;
		delete item;
	}
	//当たり判定
	void HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

private:
	int waittime;

	Player* player;
	Enemy** enemy;    //ポインタ配列
	ItemBase** item;
};

