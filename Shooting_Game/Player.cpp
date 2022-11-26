#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#define MAX_SHOT 100

Player::Player()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる
	life = 0;
	score = 0;
	bullets = new BulletsBase * [MAX_SHOT];
	for (int i = 0; i < MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる

	int bulletcount = 0;
	
	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if (KeyInput::OnPressed(MOUSE_INPUT_LEFT))
	{
		bullets[bulletcount] = new BulletStraight(static_cast<float>(x), static_cast<float>(y));
	}

	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();
			if (bullets[i]->GetBulletY() < 0)
			{
				delete bullets[i];
				bullets[i] = nullptr;
			}
		}
		else
		{
			continue;
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
#define DEBUG
#ifdef DEBUG
#endif // DEBUG


	DrawCircle(x, y, 10, GetColor(225, 0, 0), TRUE);

	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (bullets[i] == nullptr)
		{
			continue;
		}
		bullets[i]->Draw();
		DrawFormatString(0, i * 20, 0xffffff, "%2d", i);
		DrawFormatString(100, i * 20, 0xffffff, "%3d", bullets[i]->GetBulletY());
	}
}