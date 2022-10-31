#pragma once
#include "BulletsBase.h"
class CharaBase :public BulletsBase
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

	CharaBase* GetBullets(int bullet)const { return this->bullets[bullet]; }
	
protected:
	int image;
	CharaBase* bullets[30];  //�e�@���u�� TO DO
	int speed;
};