#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

class Boss :public CharaBase,public SphereCollider
{
public:
	//�R���X�g���N�^
	Boss(float Vx, float Vy, float r);  //(x���W,y���W,���a)
	//�`��ȊO�̍X�V������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
	//�����蔻��
	virtual void Hit(int damage) override;

private:
	int hp;
	int point;
	int shotCount;
};

