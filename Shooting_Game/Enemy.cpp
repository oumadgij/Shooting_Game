#include "Enemy.h"
#include "BulletStraight.h"
#include "common.h"

Enemy::Enemy(float Vx, float Vy,int r)
{
	hp = 0;
	radius = r;
	point = 0;
	speed = 1.f;
	vchara.x = Vx;
	vchara.y = Vy;
	shotCount = 0;
	bullets = new BulletsBase * [ENEMY_MAX_SHOT];
	for (int i = 0; i < ENEMY_MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	vchara.y += speed;

	int bulletcount = 0;

	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if (shotCount % 20 == 0)
	{
		bullets[bulletcount] = new BulletStraight(vchara.x, vchara.y+25,5.f);
	}

	for (int i = 0; i < ENEMY_MAX_SHOT; i++)
	{
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();
			if (bullets[i]->GetVector().y > 720)  //íeÇ™è„ÇÃâÊñ äOÇ…çsÇ¡ÇΩÇÁè¡Ç∑
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
	DrawCircle(static_cast<int>(vchara.x), static_cast<int>(vchara.y), radius, GetColor(0, 100, 255), TRUE);
	for (int i = 0; i < ENEMY_MAX_SHOT; i++)
	{
		if (bullets[i] == nullptr) continue;
		bullets[i]->Draw();
	}
}