#pragma once
#include "BulletsBase.h"
#include "DxLib.h"
class CharaBase
{
public:
	//�R���X�g���N�^
	CharaBase();
	//�f�X�g���N�^
	virtual ~CharaBase() {};
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	//�����蔻��
	virtual void Hit(int damage) = 0;

	BulletsBase** GetBullets()const { return bullets; }
	
protected:
	int image;
	float speed;
	BulletsBase** bullets;  //�e�@���u�� TO DO
};