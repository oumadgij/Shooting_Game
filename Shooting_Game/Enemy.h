#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
class Enemy : public CharaBase, public SphereCollider
{
public:
	//�R���X�g���N�^
	Enemy(float Vx,float Vy,float r);  //(x���W,y���W,���a)
	//�`��ȊO�̍X�V������
	virtual void Update() override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
	//�����蔻��
	virtual void Hit(int damage) override;
	//Hp��0��
	bool HpCheck();
	int GetPoint()const { return point; }
	int GetHP()const { return hp; }
	void DeleteBullet(int bulletcount);

private:
	int hp;
	int point;
	int shotCount;
};

