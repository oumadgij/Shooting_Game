#pragma once
#include "AbstractScene.h"
class GameMain : public AbstractScene
{
private:
	int player;
	int* enemy;    //�|�C���^�z�� TO DO

public:
	void HitCheck();
	AbstractScene* Update() override;
	void Draw() const override;
};

