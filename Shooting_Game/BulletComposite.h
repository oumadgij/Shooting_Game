#pragma once
#include "BulletsBase.h"
class BulletComposite :public BulletsBase
{
public:
	//�R���X�g���N�^
	BulletComposite(float x, float y, float sp, float r, int angle, int updamage);
	//�`��ȊO�̍X�V������
	void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	void Draw()const override;
private:
	int angle;
};