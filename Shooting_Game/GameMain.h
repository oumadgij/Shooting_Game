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
	GameMain();
	//�f�X�g���N�^
	virtual ~GameMain() {};
	//�����蔻��
	void HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

