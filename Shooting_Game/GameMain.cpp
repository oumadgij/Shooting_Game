#include "GameMain.h"
#include "DxLib.h"
#include <time.h>

GameMain::GameMain()
{
	player = new Player;
	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	item = new ItemBase * [10];
	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr;
	}
	enemy[0] = new Enemy(500, 0.f, 30);
}

AbstractScene* GameMain::Update()
{
	player->Update();
	int enemyCount;
	//エネミーが存在しているかどうか
	/*for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			enemy[enemyCount] = new Enemy(500, 0.f, 30);
			break;
		}
	}*/
	//for (enemyCount = 0; enemyCount < 10; enemyCount++)
	//{
	//	if (enemy[enemyCount] != nullptr)
	//	{
	//		enemy[enemyCount]->Update();
	//		if (enemy[enemyCount]->GetLocation().y > 720)  //エネミーが画面外に行ったか
	//		{
	//			delete enemy[enemyCount];
	//			enemy[enemyCount] = nullptr;
	//		}
	//	}
	//}
	if (enemy[0] != nullptr)
	{
		enemy[0]->Update();
		if (enemy[0]->GetLocation().y > 720)  //エネミーが画面外に行ったか
		{
			delete enemy[0];
			enemy[0] = nullptr;
		}
	}
	
	
	HitCheck();

	return this;
}

void GameMain::HitCheck()
{
	BulletsBase** bullet;
	bullet = player->GetBullets();
	/*プレイヤーの弾とエネミーの当たり判定*/
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{	
		//エネミーが存在する時
		if (enemy[enemyCount] != nullptr)
		{
			for (int bulletCount = 0; bulletCount < 30; bulletCount++)
			{
				//弾が存在する時
				if (bullet[bulletCount] != nullptr)
				{
					//プレイヤーの弾がエネミーにあったたか
					if (enemy[enemyCount]->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
					{
						//当たった時
						enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());  //エネミーにダメージを与える
						delete bullet[bulletCount];   //弾を消す
						bullet[bulletCount] = nullptr;
					}
					//エネミーのHPが０になったか
					if (enemy[enemyCount]->HpCheck())
					{
						delete enemy[enemyCount];
						enemy[enemyCount] = nullptr;
						break;
					}
				}
			}
		}
	}
}

void GameMain::Draw() const
{
	player->Draw();
	/*for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)
		{
			enemy[enemyCount]->Draw();
		}
	}*/
	if (enemy[0] != nullptr)
	{
		enemy[0]->Draw();
	}
}