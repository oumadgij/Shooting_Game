#pragma once
#include "ItemBase.h"

class DropItem :public ItemBase
{
public:
	DropItem(VECTOR location, float radius, int type, float speed);
	//�`��ȊO�̍X�V������
	virtual void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const override;

private:
};

