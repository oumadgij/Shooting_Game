#pragma once
#include "SphereCollider.h"

class BulletsBase : public SphereCollider
{
public:
	//�R���X�g���N�^
	BulletsBase();
	//�f�X�g���N�^
	virtual ~BulletsBase() {};
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }

protected:
	int damage;   //�_���[�W
	int speed;    //�X�s�[�h
	int x, y;     //X���W,Y���W
};