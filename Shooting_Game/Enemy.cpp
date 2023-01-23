#include "Enemy.h"
#include "BulletStraight.h"
#include "BulletVLine.h"
#include "common.h"
#define _USE_MATH_DEFINES
#include <math.h>


Enemy::Enemy(float Vx, float Vy,float r)
{
	hp = 10;
	radius = r;
	point = 0;
	speed = 0.5f;
	location.x = Vx;
	location.y = Vy;
	shotCount = 0;
	eType = ENEMY_TYPE::DEFAULT;
	bullets = new BulletsBase * [ENEMY_MAX_SHOT];
	for (int i = 0; i < ENEMY_MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	Move();

	int bulletcount = 0;
	//弾が存在するかしないか調べる
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)  //存在しない時にループを抜ける
		{
			break;
		}
	}

	if (++shotCount % 120 == 0)
	{
		//弾の実体化
		if (eType == ENEMY_TYPE::STRAIGHT)  //ストレート
		{
			bullets[bulletcount] = new BulletStraight(location.x, location.y + 25, 5.f, 10, 0);
		}
		if (eType == ENEMY_TYPE::VLINE)     //V字
		{
			bullets[bulletcount] = new BulletVLine(location.x, location.y, 5.f, 10, 85);
			bullets[bulletcount + 1] = new BulletVLine(location.x, location.y, 5.f, 10, 95);
		}
		shotCount = 0;
	}

	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();//弾を動かす
			if (bullets[bulletcount]->GetLocation().y > 720) //弾が下の画面外に行ったか
			{
				//画面外に行ったとき弾を消す
				DeleteBullet(bulletcount);
			}
		}
	}
}

/*エネミーを動かす*/
void Enemy::Move()
{
	location.y += speed;
}

/*敵の動きタイプを選ぶ*/
void Enemy::SelectType(int type)
{
	switch (type)
	{
	case 0:
		eType = ENEMY_TYPE::STRAIGHT;  //ストレート
		break;
	case 1:
		eType = ENEMY_TYPE::VLINE;     //V字
		break;
	case 2:
		eType = ENEMY_TYPE::REPEL;     //打ち返し
		break;
	case 3:
		eType = ENEMY_TYPE::DEFAULT;   //何もしない
		break;
	}
}

/*当たり判定*/
void Enemy::Hit(int damage)
{
	hp -= damage;
}

/*HPが０以下かチェックする*/
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

	//HPが0より大きい時表示する
	if (hp > 0)
	{
		DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(0, 100, 255), TRUE);
	}
	
	for (int bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), GetColor(255, 180, 0), TRUE);
		}
	}
}

/*弾を消す*/
void Enemy::DeleteBullet(int bulletcount)
{
	delete bullets[bulletcount];
	bullets[bulletcount] = nullptr;
}

/*打ち返しの弾の実体化*/
void Enemy::RepelMaterialization()
{
	if (bullets[0] == nullptr)
	{
		if (eType == ENEMY_TYPE::REPEL)     //打ち返し
		{
			bullets[0] = new BulletStraight(location.x, location.y, 5.f, 10, 0);
		}
	}
}