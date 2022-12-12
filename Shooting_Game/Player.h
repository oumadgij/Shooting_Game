#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#include "ItemBase.h"

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
	virtual void Hit(int damage)override;
	void Hit(ITEM_TYPE item,int effects);
	void LifeCheck();
	void DeleteBullet(int bulletcount);
	int GetScore()const { return score; }

private:
	int x, y;
	int score;   //�X�R�A
	int life;    //HP
	int shotCount;
	int upDamage;
};

