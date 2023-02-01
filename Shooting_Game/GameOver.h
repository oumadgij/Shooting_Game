#pragma once
#include "AbstractScene.h"
class GameOver :public AbstractScene
{
public:
	//コンストラクタ
	GameOver();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

