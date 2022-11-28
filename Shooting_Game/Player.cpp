#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#include "common.h"

Player::Player()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる
	vchara.x = static_cast<float>(x);
	vchara.y = static_cast<float>(y);
	life = 0;
	radius = 10;
	score = 0;
	shotCount = 0;
	bullets = new BulletsBase * [MAX_SHOT];
	for (int i = 0; i < MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる
	vchara.x = static_cast<float>(x);
	vchara.y = static_cast<float>(y);
	if (vchara.x < 0) vchara.x = 0.f;
	else if (vchara.x > 1280) vchara.x = 1280.f;
	if (vchara.y < 0) vchara.y = 0.f;
	else if (vchara.y > 720) vchara.y = 720.f;

	int bulletcount = 0;
	
	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if ((shotCount % 5) == 0 && (KeyInput::OnPressed(MOUSE_INPUT_LEFT)))
	{
		bullets[bulletcount] = new BulletStraight(vchara.x, vchara.y,-5.f);
	}

	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();
			if (bullets[i]->GetBulletY() < 0)  //弾が上の画面外に行ったら消す
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

	++shotCount;
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


	DrawCircle(static_cast<int>(vchara.x), static_cast<int>(vchara.y), radius, GetColor(225, 0, 0), TRUE);

	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (bullets[i] == nullptr) continue;
		bullets[i]->Draw();
	}
}