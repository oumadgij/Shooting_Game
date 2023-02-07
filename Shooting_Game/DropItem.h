#pragma once
#include "ItemBase.h"

enum class ITEM_TYPE
{
	HEAL = 0,   //HP��
	ATTACK,     //�U���̓A�b�v
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
	int GetEffects(int t)const { return effects[t]; }

private:
	const int effects[3] = { 2,1,0 };  //���� 0���:�񕜗� 1���:�オ��U���� 2���:�Ȃɂ��Ȃ�
	ITEM_TYPE type;  //�A�C�e���^�C�v
};

