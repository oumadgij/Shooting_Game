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
	enemyType = ENEMY_TYPE::DEFAULT;
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

	if (120 < ++shotCount)
	{
		//弾の実体化
		if (enemyType == ENEMY_TYPE::STRAIGHT)  //ストレート
		{
			bullets[bulletcount] = new BulletStraight(location.x, location.y + 25, 5.f, 5, 0);  //radius 元10  TODO
		}
		if (enemyType == ENEMY_TYPE::VLINE)     //V字
		{
			bullets[bulletcount] = new BulletVLine(location.x, location.y, 5.f, 5, 85,0);  //radius 元10  TODO
			bullets[bulletcount + 1] = new BulletVLine(location.x, location.y, 5.f, 5, 95,0);  //radius 元10  TODO
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
		enemyType = ENEMY_TYPE::STRAIGHT;  //ストレート
		break;
	case 1:
		enemyType = ENEMY_TYPE::VLINE;     //V字
		break;
	case 2:
		enemyType = ENEMY_TYPE::REPEL;     //打ち返し
		break;
	case 3:
		enemyType = ENEMY_TYPE::DEFAULT;   //何もしない
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

	//HPが0より大きい時敵を表示する
	if (hp > 0)
	{
		//ストレートで弾を撃つ敵の色 青
		if (enemyType == ENEMY_TYPE::STRAIGHT)
		{
			DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x0064C5, TRUE);
		}
		//V字で弾を撃つ敵の色 緑
		if (enemyType == ENEMY_TYPE::VLINE)
		{
			DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x008E69, TRUE);
		}
		//死んだときに弾を出す敵の色 ピンク
		if (enemyType == ENEMY_TYPE::REPEL)
		{
			DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0xD5648D, TRUE);
		}
	}
	
	//弾の表示
	for (int bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), 0xFFB400, TRUE);
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
		if (enemyType == ENEMY_TYPE::REPEL)     //打ち返し
		{
			bullets[0] = new BulletStraight(location.x, location.y, 5.f, 10, 0);
		}
	}
}