#pragma once
#include "ItemBase.h"

enum class ITEM_TYPE
{
	HEAL = 0,   //HP��
	ATTACK,     //�U���̓A�b�v
	DEFAULT
};

enum class ITEM_EFFECTS
{
	HEAL = 2,  //�񕜗�
	ATTACK = 1, //�オ��U����
	DEFAULT
};

class DropItem :public ItemBase
{
public:
	DropItem(VECTOR location, float radius, int type, float speed);
	//�`��ȊO�̍X�V������
	virtual void Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const override;
	ITEM_TYPE GetType()const { return type; }
	ITEM_EFFECTS GetEffects()const { return effects; }

private:
	ITEM_TYPE type;
	ITEM_EFFECTS effects;
};

