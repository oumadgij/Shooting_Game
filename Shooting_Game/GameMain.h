#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
class GameMain : public AbstractScene
{
private:
	Player player;
	Enemy** enemy[10];    //ポインタ配列　仮置き　 TO DO

public:
	//コンストラクタ
	GameMain();
	//デストラクタ
	virtual ~GameMain() {};
	//当たり判定
	void HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

