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
	virtual void Hit() = 0;

	BulletsBase** GetBullets()const { return bullets; }
	VECTOR GetVector()const { return vchara; }
	
protected:
	int image;
	float speed;
	VECTOR vchara;
	BulletsBase** bullets;  //�e�@���u�� TO DO
};