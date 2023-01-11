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
	int shotCount;
	int upDamage;
	int bulletLine;  //�e���o���
	BULLET_TYPE bType;
};

