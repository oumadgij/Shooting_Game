#pragma once
#include "SphereCollider.h"

enum class ITEM_TYPE
{
	HP = 0,
	DEFAULT
};

enum class ITEM_EFFECTS
{
	HEAL = 10,
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