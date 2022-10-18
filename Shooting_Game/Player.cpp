#include "Player.h"
#include "DxLib.h"
#include "KeyInput.h"

Player::Player()
{
	life = 0;
	score = 0;
	x = 0;
	y = 0;
}

void Player::Update()
{
	score = 0;
	life = 0;
	GetMousePoint(&x, &y);   //マウスの座標を自機に
	if (KeyInput::OnPressed(MOUSE_INPUT_LEFT))
	{
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
	if (KeyInput::OnPressed(MOUSE_INPUT_LEFT))
	{
		
	}
}