#include "ItemBase.h"

ItemBase::ItemBase()
{
	location.x = 0;
	location.y = 0;
	location.z = 0;
	radius = 0;
	speed = 0;
	effects = ITEM_EFFECTS::DEFAULT;
	type = ITEM_TYPE::DEFAULT;
}