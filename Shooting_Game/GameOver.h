#pragma once
#include "AbstractScene.h"
class GameOver :public AbstractScene
{
public:
	//�R���X�g���N�^
	GameOver();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

