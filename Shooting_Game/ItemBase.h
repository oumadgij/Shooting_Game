#pragma once
#include "SphereCollider.h"

class ItemBase:public SphereCollider
{
public:
	//�R���X�g���N�^
	ItemBase();
	//�f�X�g���N�^
	virtual ~ItemBase() {};
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;

protected:
	float speed;
};