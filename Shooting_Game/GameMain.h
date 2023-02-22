#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "DropItem.h"

class GameMain : public AbstractScene
{
public:
	//�R���X�g���N�^
	GameMain();
	//�f�X�g���N�^
	~GameMain() 
	{ 
		delete player; 
		delete enemy;
		delete drop_item;
	}
	//�����蔻��
	void HitCheck();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

private:
	int waittime;  //�G�l�~�[���̉��̑҂�����
	int secenWaitTime; //�V�[���J�ڂ܂ł̑҂�����
	int bossAppearanceTime;  //�{�X�o���܂ł̎���
	bool playerDie;  //�v���C���[�����񂾂��ǂ��� true:���� false:����ł��Ȃ�
	Player* player;
	Boss* boss;
	Enemy** enemy;
	DropItem** drop_item;
};

