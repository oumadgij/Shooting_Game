#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"
class GameMain : public AbstractScene
{
private:
	Player *player;
	Enemy** enemy;    //�|�C���^�z��@���u���@ TO DO
	ItemBase** item;

public:
	//�R���X�g���N�^
	GameMain();
	//�f�X�g���N�^
	~GameMain() 
	{ 
		delete player; 
		delete enemy;
		delete item;
	}
	//�����蔻��
	void HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

