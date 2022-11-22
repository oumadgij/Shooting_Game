#pragma once
#include "BulletsBase.h"
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
	virtual void Hit() = 0;

	//GetBullets()�@�@����
	BulletsBase** GetBullets()const { return bullets; }
	
protected:
	int image;
	int speed;
	BulletsBase** bullets;  //�e�@���u�� TO DO
};