#pragma once

class BulletsBase
{
public:
	virtual ~BulletsBase() {};

	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int GetDamage()const { return damage; }

private:
	int damage;   //�_���[�W
	int speed;    //�X�s�[�h
};