#include "Player.h"
#include "DxLib.h"
#include "KeyInput.h"

#define MAX_SHOT 30

Player::Player()
{
	life = 0;
	score = 0;
	x = 0;
	y = 0;
}

void Player::Update()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機に

	if (KeyInput::OnPressed(MOUSE_INPUT_LEFT))
	{
		if (shotflg==false)
		{
			bullety = y;
			bulletx = x;
			shotflg = !shotflg;
		}
	}

	if (shotflg && bullety < 0)
	{
		shotflg = !shotflg;
	}
	else
	{
		bullety -= BulletsBase::speed;
	}
}

void Player::Hit()
{

}

void Player::LifeCheck()
{

}

void Player::Draw()const
{
	DrawCircle(x, y, 10, GetColor(225, 0, 0), TRUE);
	if (shotflg)
	{
		DrawCircle(bulletx, bullety, 10, GetColor(255, 0, 100), TRUE);
		DrawString(0, 0, "OnPressed", GetColor(255, 0, 100));
	}
}