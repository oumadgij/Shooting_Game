#pragma once
#include "BulletsBase.h"
class BulletVLine : public BulletsBase
{
public:
	//�R���X�g���N�^
	BulletVLine(float x, float y, float sp, float r, int angle,int updamage);
	//�`��ȊO�̍X�V������
	void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	void Draw()const override;

private:
	int angle;
};

