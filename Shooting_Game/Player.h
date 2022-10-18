#pragma once
#include "CharaBase.h"
#include "BulletsBase.h"
class Player : public CharaBase,public BulletsBase
{
public:
	//�`��ȊO�̍X�V������
	void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	void Draw()const override;
	//�����蔻��
	void Hit()override;
	void LifeCheck();
	int GetScore()const { return score; }

private:
	int x, y;    //X���W,Y���W
	int score;   //�X�R�A
	int life;    //HP
};

