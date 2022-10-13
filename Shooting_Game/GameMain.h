#pragma once
#include "AbstractScene.h"
#include "Player.h"
class GameMain : public AbstractScene
{
private:
	Player player;
	int* enemy[10];    //ポインタ配列　仮置き　 TO DO

public:
	//コンストラクタ
	void HitCheck();
	//デストラクタ
	virtual ~GameMain() {};
	AbstractScene* Update() override;
	void Draw() const override;
};

