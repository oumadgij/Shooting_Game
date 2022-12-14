#include "DropItem.h"

DropItem::DropItem(VECTOR location, float radius, int type, float speed)
{
	this->location = location;
	this->radius = radius;
	this->speed = speed;
	//タイプ
	if (type == 0)
	{
		this->type = ITEM_TYPE::HEAL;
	}
	if (type == 1)
	{
		this->type = ITEM_TYPE::ATTACK;
	}
	//効果
	if (this->type == ITEM_TYPE::HEAL)
	{
		effects = ITEM_EFFECTS::HEAL;
	}
	if (this->type == ITEM_TYPE::ATTACK)
	{
		effects = ITEM_EFFECTS::ATTACK;
	}
}

void DropItem::Update()
{
	location.y += speed;
}

void DropItem::Draw()const
{
	if (this->type == ITEM_TYPE::HEAL)
	{
		DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(0, 180, 200), TRUE);
	}
	if (this->type == ITEM_TYPE::ATTACK)
	{
		DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(180, 50, 200), TRUE);
	}
}