#pragma once
#include "SphereCollider.h"

enum class ITEM_TYPE
{
	HEAL = 0,   //HP��
	ATTACK,     //�U���̓A�b�v
	DEFAULT
};

enum class ITEM_EFFECTS
{
	HEAL = 10,  //�񕜗�
	ATTACK = 3, //�オ��U����
	DEFAULT
};

class ItemBase:public SphereCollider
{
public:
	//�R���X�g���N�^
	ItemBase();
	//�f�X�g���N�^
	virtual ~ItemBase() {};
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	ITEM_TYPE GetType()const { return type; }
	ITEM_EFFECTS GetEffects()const { return effects; }

protected:
	float speed;
	ITEM_TYPE type;
	ITEM_EFFECTS effects;
};