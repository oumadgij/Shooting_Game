#pragma once
#include "BulletsBase.h"

class BulletStraight :public BulletsBase
{
public:
	BulletStraight(float x, float y);
	//~BulletStraight();
	//�`��ȊO�̍X�V������
	void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	void Draw()const override;

private:
};

