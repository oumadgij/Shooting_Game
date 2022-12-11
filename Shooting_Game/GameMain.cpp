#include "GameMain.h"
#include "DxLib.h"
#include "common.h"
#include "DropItem.h"

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
	waittime = 0;
}

AbstractScene* GameMain::Update()
{
	player->Update();
	int enemyCount;
	if (++waittime % 100 == 0)
	{
		for (enemyCount = 0; enemyCount < 10; enemyCount++)
		{
			if (enemy[enemyCount] == nullptr)//エネミーが存在しない時
			{   //ランダム位置にエネミーを配置する
				enemy[enemyCount] = new Enemy(static_cast<float>(rand() % WINDOW_WIDTH-50)+30, 0.f, 30);
				waittime = 0;
				break;
			}
		}
	}
	
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)  //エネミーが存在する時
		{
			enemy[enemyCount]->Update(); //エネミーを動かす
			if (enemy[enemyCount]->GetLocation().y-30 > 720)  //エネミーが画面外に行った時
			{   //エネミーを消す
				delete enemy[enemyCount];
				enemy[enemyCount] = nullptr;
			}
		}
	}

	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (item[itemCount] != nullptr)  //アイテムが存在する時
		{
			item[itemCount]->Update();
			if (item[itemCount]->GetLocation().y - 5 > 720) //エネミーが画面外に行った時
			{
				//アイテムを消す
				delete item[itemCount];
				item[itemCount] = nullptr;
			}
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
			for (int bulletCount = 0; bulletCount < MAX_SHOT; bulletCount++)
			{
				//弾が存在する時
				if (bullet[bulletCount] != nullptr)
				{
					//プレイヤーの弾がエネミーにあったたか
					if (enemy[enemyCount]->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
					{
						//当たった時
						enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());  //エネミーのHPを減らす
						player->DeleteBullet(bulletCount);  //弾を消す
					}
					//エネミーのHPが０になったか
					if (enemy[enemyCount]->HpCheck())
					{  
						for (int itemCount = 0; itemCount < 10; itemCount++)
						{
							if (item[itemCount] == nullptr)
							{
								//アイテムを生成する
								item[itemCount] = new DropItem(enemy[enemyCount]->GetLocation(), 5, 0, 0.8f);
								break;
							}
						}
						//エネミーを消す
						delete enemy[enemyCount];
						enemy[enemyCount] = nullptr;
						break;
					}
				}
			}
		}
	}

	/*エネミーの弾とプレイヤーの当たり判定*/
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{   //エネミーが存在するかどうか
		if (enemy[enemyCount] == nullptr) break;
		bullet = enemy[enemyCount]->GetBullets();

		for (int bulletCount = 0; bulletCount < ENEMY_MAX_SHOT; bulletCount++)
		{
			//弾が存在する時
			if (bullet[bulletCount] != nullptr)
			{   //エネミーの弾がプレイヤーに当たったか
				if (player->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
				{
					//当たった時
					player->Hit(bullet[bulletCount]->GetDamage());  //プレイヤーのHPを減らす
					enemy[enemyCount]->DeleteBullet(bulletCount); //弾を消す
				}
			}
		}
	}

	/*アイテムとプレイヤーの当たり判定*/
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{   //アイテムが存在するか
		if (item[itemCount] == nullptr) continue;

		//プレイヤーがアイテムに当たったか
		if (item[itemCount]->HitSphere(player->GetLocation(), player->GetRadius()))
		{   //アイテムの効果をプレイヤーに反映する
			player->Hit(item[itemCount]->GetType(), static_cast<int>(item[itemCount]->GetEffects()));
			delete item[itemCount];
			item[itemCount] = nullptr;
		}
	}
}

void GameMain::Draw() const
{
#define DEBUG
#ifdef DEBUG
	DrawString(0, 100, "エネミー", 0xff0000);
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] != nullptr)
		{
			if (i <= 3)
			{
				DrawFormatString(0 + i * 120, 120, 0xffffff, "Enemy%2d: %2d", i, enemy[i]->GetHP());
			}
			else if (i <= 7)
			{
				DrawFormatString(0 + (i - 4) * 120, 120 + 30, 0xffffff, "Enemy%2d: %2d", i, enemy[i]->GetHP());
			}
			else
			{
				DrawFormatString(0 + (i - 8) * 120, 120 + 60, 0xffffff, "Enemy%2d: %2d", i, enemy[i]->GetHP());
			}
		}
	}
#endif // DEBUG


	player->Draw();
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)
		{
			enemy[enemyCount]->Draw();
		}
	}
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (item[itemCount] != nullptr)  //アイテムが存在する時
		{
			item[itemCount]->Draw();
		}
	}
}