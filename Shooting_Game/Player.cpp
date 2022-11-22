#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"

Player::Player()
{
	x = 0;
	y = 0;
	life = 0;
	score = 0;
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる

	int bulletcount = 0;
	if (KeyInput::OnPressed(MOUSE_INPUT_LEFT))
	{
		for (bulletcount = 0; bulletcount < 30; bulletcount++)
		{
			if (bullets[bulletcount] == nullptr)
			{
				bullets[bulletcount] = new BulletStraight(static_cast<float>(x), static_cast<float>(y));
				break;
			}
		}
	}

	for (int i = 0; i < 30; i++)
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();
			if (bullets[i]->GetBulletY() < 0)
			{
				bullets[i] = nullptr;
			}
		}
		else
		{
			break;
		}
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
//#define DEBUG
#ifdef DEBUG

#endif // DEBUG


	DrawCircle(x, y, 10, GetColor(225, 0, 0), TRUE);

	for (int i = 0; i < 30; i++)
	{
		if (bullets[i] == nullptr)
		{
			break;
		}
		bullets[i]->Draw();
	}
}