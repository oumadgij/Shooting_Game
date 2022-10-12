#pragma once
#include "AbstractScene.h"
class GameMain : public AbstractScene
{
private:
	int player;
	int* enemy;    //ポインタ配列 TO DO

public:
	void HitCheck();
	AbstractScene* Update() override;
	void Draw() const override;
};

