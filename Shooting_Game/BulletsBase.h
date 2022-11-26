#pragma once
#include "SphereCollider.h"
#include "DxLib.h"

class BulletsBase :public SphereCollider
{
public:
	//�R���X�g���N�^
	/*BulletsBase(float x, float y);*/
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }
	float GetBulletY()const { return Vbullet.y; }

protected:
	int damage;   //�_���[�W
	float speed;    //�X�s�[�h
	int image;
	VECTOR Vbullet;
};