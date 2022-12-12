#include "Enemy.h"
#include "BulletStraight.h"
#include "common.h"

Enemy::Enemy(float Vx, float Vy,float r)
{
	hp = 10;
	radius = r;
	point = 0;
	speed = 0.5f;
	location.x = Vx;
	location.y = Vy;
	shotCount = 0;
	bullets = new BulletsBase * [ENEMY_MAX_SHOT];
	for (int i = 0; i < ENEMY_MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	location.y += speed;

	int bulletcount = 0;

	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if (++shotCount % 120 == 0)
	{
		bullets[bulletcount] = new BulletStraight(location.x, location.y+25,5.f,10,0);
	}

	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();//弾を動かす
			if (bullets[bulletcount]->GetLocation().y > 720) //弾が下の画面外に行ったか
			{
				//画面外に行ったとき
				DeleteBullet(bulletcount);
			}
		}
	}
}

void Enemy::Hit(int damage)
{
	hp -= damage;
}

bool Enemy::HpCheck()
{
	if (hp <= 0)
	{
		return true;
	}
	return false;
}

void Enemy::Draw()const
{
#define DEBUG
#ifdef DEBUG
#endif // DEBUG


	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(0, 100, 255), TRUE);
	for (int bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), GetColor(255, 180, 0), TRUE);
		}
	}
}

void Enemy::DeleteBullet(int bulletcount)
{
	delete bullets[bulletcount];
	bullets[bulletcount] = nullptr;
}