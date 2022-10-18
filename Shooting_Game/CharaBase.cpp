#include "CharaBase.h"

CharaBase::CharaBase()
{
	for (int i = 0; i < 10; i++)
	{
		bullets[i] = 0;
	}
	speed = 0;
	image = 0;
}