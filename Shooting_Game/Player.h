#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#include "ItemBase.h"

enum class BULLET_TYPE
{
	STRAIGHT,   //�X�g���[�g
	VLINE       //V��
};

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
	virtual void Hit(int damage)override;  //�e�ɓ����������̏���
	void Hit(ITEM_TYPE item,int effects);  //�A�C�e���ɓ����������̏���
	bool LifeCheck();
	void DeleteBullet(int bulletcount);
	int GetScore()const { return score; }

private:
	void BulletSelect(int bulletcount);  //�e�̎�ނ�I��
	int x, y;    //���W
	int score;   //�X�R�A
	int life;    //HP
	int shotCount;//�U���Ԋu
	int upDamage; //�U���͂̑�����
	int bulletLine;  //�e���o���   TODO �P�񂩂�Q��ɑ��₻���Ƃ��č�����ϐ��B�܂�����������Ă��Ȃ�
	int interval;   //attackInterval�̓Y����
	int comparison; //damageComparison�̓Y����
	const int attackInterval[5] = { 5,10,15,20,25 };
	const int damageComparison[5] = { 5,10,15,20,25 };
	BULLET_TYPE bulletType;
};

