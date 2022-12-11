#include "DropItem.h"

DropItem::DropItem(VECTOR location, float radius, int type, float speed)
{
	this->location = location;
	this->radius = radius;
	this->speed = speed;

	if (type == 0)
	{
		this->type = ITEM_TYPE::HP;
	}

	if (this->type == ITEM_TYPE::HP)
	{
		effects = ITEM_EFFECTS::HEAL;
	}
}

void DropItem::Update()
{
	location.y += speed;
}

void DropItem::Draw()const
{
	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(0, 180, 200), TRUE);
}