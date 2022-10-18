#include "Player.h"
#include "DxLib.h"
#include "KeyInput.h"

void Player::Update()
{
	score = 0;
	life = 0;
	GetMousePoint(&x, &y);
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
	if (KeyInput::OnPressed(MOUSE_INPUT_LEFT))
	{
		DrawString(10, 10, "OnPressed", GetColor(225, 200, 0));
	}
}