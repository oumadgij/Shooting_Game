#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

struct actionInfo
{
	int pattern;  //�s���p�^�[��
	VECTOR destination; //�ړI�n
	int next;  //���̔z��ԍ�
	int waittime; //�҂�����
	int attacktype;  //�U���̎��
};

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
	//�{�X�𓮂���
	void Move();
	//CSV�t�@�C���ǂݍ���
	void InputCSV();
	//�e������
	void DeleteBullet(int bulletcount);
	//Hp��0�����ׂ�
	bool HpCheck();
	int GetHP()const { return hp; }

private:
	int hp;
	int point;
	int shotCount;   //�e���o�鑁��
	int waittime;    //���̍s���Ɉڂ�܂ł̑҂�����
	int nowIndex;    //���݂̓Y����

	actionInfo moveinfo[4];
};

