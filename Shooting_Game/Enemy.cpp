#include "Enemy.h"
#include "BulletStraight.h"
#define MAX_SHOT 3

Enemy::Enemy(float Vx, float Vy)
{
	hp = 0;
	point = 0;
	speed = 1.f;
	vchara.x = Vx;
	vchara.y = Vy;
	shotCount = 0;
	bullets = new BulletsBase * [MAX_SHOT];
	for (int i = 0; i < MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	vchara.y += speed;

	int bulletcount = 0;

	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if ((shotCount % 10) == 0)
	{
		bullets[bulletcount] = new BulletStraight(vchara.x, vchara.y+25,5.f);
	}

	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();
			if (bullets[i]->GetBulletY() > 720)  //íeÇ™è„ÇÃâÊñ äOÇ…çsÇ¡ÇΩÇÁè¡Ç∑
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

void Enemy::Hit()
{

}

void Enemy::HpCheck()
{

}

void Enemy::Draw()const
{
	DrawCircle(static_cast<int>(vchara.x), static_cast<int>(vchara.y), 20, GetColor(0, 100, 255), TRUE);
	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (bullets[i] == nullptr) continue;
		bullets[i]->Draw();
	}
}