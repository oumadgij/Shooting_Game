#pragma once
#include "BulletsBase.h"

class BulletStraight :public BulletsBase
{
public:
	//�R���X�g���N�^
	BulletStraight(float x, float y,float sp,float r,int updamage);
	//~BulletStraight();
	//�`��ȊO�̍X�V������
	void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	void Draw()const override;
private:
};

