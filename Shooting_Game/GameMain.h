#pragma once
#include "AbstractScene.h"
#include "Player.h"
class GameMain : public AbstractScene
{
private:
	Player player;
	int* enemy[10];    //�|�C���^�z��@���u���@ TO DO

public:
	//�R���X�g���N�^
	void HitCheck();
	//�f�X�g���N�^
	virtual ~GameMain() {};
	AbstractScene* Update() override;
	void Draw() const override;
};

