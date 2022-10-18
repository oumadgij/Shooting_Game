#pragma once
#include "CharaBase.h"
#include "BulletsBase.h"
class Enemy : public CharaBase, public BulletsBase
{
public:
	//�R���X�g���N�^
	Enemy();
	//�`��ȊO�̍X�V������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
	//�����蔻��
	virtual void Hit() override;
	//Hp��0��
	void HpCheck();
	int GetPoint()const { return point; }

private:
	int hp;
	int point;
};

