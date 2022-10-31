#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Player : public CharaBase,public SphereCollider
{
public:
	//�R���X�g���N�^
	Player();
	//�`��ȊO�̍X�V������
	virtual void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const override;
	//�����蔻��
	virtual void Hit()override;
	void LifeCheck();
	int GetScore()const { return score; }

private:
	int x, y;    //X���W,Y���W
	int score;   //�X�R�A
	int life;    //HP
};

