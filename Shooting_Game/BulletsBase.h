#pragma once
#include "SphereCollider.h"

class BulletsBase :public SphereCollider
{
public:
	//�R���X�g���N�^
	BulletsBase();
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }
	void UpDamage(int damage) { this->damage += damage; }

protected:
	int damage;   //�_���[�W
	float speed;    //�X�s�[�h
	int image;
};