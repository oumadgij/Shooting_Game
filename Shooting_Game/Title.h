#pragma once
#include "AbstractScene.h"
class Title :public AbstractScene
{
public:
	//�R���X�g���N�^
	Title();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
private:
};

