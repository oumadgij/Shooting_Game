#pragma once
#include "ItemBase.h"

class DropItem :public ItemBase
{
public:
	DropItem(VECTOR location, float radius, int type, float speed);
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•
	virtual void Update()override;
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•
	virtual void Draw()const override;

private:
};

