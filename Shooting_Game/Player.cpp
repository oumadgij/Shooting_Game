#include "Player.h"
#include "DxLib.h"

void Player::Update()
{
	score = 0;
	life = 0;
}

void Player::Hit()
{

}

void Player::LifeCheck()
{

}

void Player::Draw()const
{
	DrawCircle(200, 300, 10, GetColor(225, 0, 0), TRUE);
}