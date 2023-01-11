#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

enum class ENEMY_TYPE
{
	STRAIGHT,   //�X�g���[�g
	VLINE,      //V��
	REPEL,      //�ł��Ԃ�
	DEFAULT     //�������Ȃ�
};

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
	//�G�l�~�[�𓮂���
	void Move();
	//�G�̓����^�C�v��I��
	void SelectType(int type);
	//Hp��0��
	bool HpCheck();
	//�e������
	void DeleteBullet(int bulletcount);
	//�ł��Ԃ��̒e�̎��̉�
	void RepelMaterialization();
	//�Q�b�^�[
	int GetPoint()const { return point; }
	int GetHP()const { return hp; }
	ENEMY_TYPE GetEnemyType()const { return eType; }

private:
	int hp;
	int point;
	int shotCount;
	ENEMY_TYPE eType;
};

