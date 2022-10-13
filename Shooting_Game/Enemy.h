#pragma once
#include "CharaBase.h"
#include "BulletsBase.h"
class Enemy : public CharaBase, public BulletsBase
{
public:
	void Update() override;
	void Draw() const override;
	void Hit() override;
	void HpCheck();
	int GetPoint()const { return point; }

private:
	int hp;
	int point;
};

