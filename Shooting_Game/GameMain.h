#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "DropItem.h"

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
		delete drop_item;
	}
	//当たり判定
	void HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

private:
	int waittime;
	int secenWaitTime; //シーン遷移までの待ち時間
	bool playerDie;  //プレイヤーが死んだかどうか true:死んだ false:死んでいない
	Player* player;
	Boss* boss;
	Enemy** enemy;
	DropItem** drop_item;
};

