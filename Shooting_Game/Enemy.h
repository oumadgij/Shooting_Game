#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Enemy : public CharaBase, public SphereCollider
{
public:
	//�R���X�g���N�^
	Enemy(float Vx,float Vy,int r);  //(x���W,y���W,���a)
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
	int shotCount;
};

