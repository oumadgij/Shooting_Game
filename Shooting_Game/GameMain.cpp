#include "GameMain.h"
#include "DxLib.h"
#include "common.h"
#include <time.h>
#include "GameOver.h"

GameMain::GameMain()
{
	player = new Player;
	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	drop_item = new DropItem * [10];
	for (int i = 0; i < 10; i++)
	{
		drop_item[i] = nullptr;
	}
	waittime = 0;
	secenWaitTime = 0;
	playerDie = false;
}

AbstractScene* GameMain::Update()
{
	//プレイヤーが死んでいない時のみ操作を受け付ける
	if (!playerDie)
	{
		player->Update();
	}

	int enemyCount;
	/*エネミーの実体化*/
	if (++waittime % 100 == 0)
	{
		for (enemyCount = 0; enemyCount < 10; enemyCount++)
		{
			if (enemy[enemyCount] == nullptr)//エネミーが存在しない時
			{   //ランダム位置にエネミーを配置する
				enemy[enemyCount] = new Enemy(static_cast<float>(rand() % WINDOW_WIDTH-50)+30, 0.f, 30);
				//エネミーのタイプをランダムに決定する
				//0:ストレート 1:vライン 2:打ち返し 3:何もしない
				enemy[enemyCount]->SelectType(rand() % 4);
				waittime = 0;
				break;
			}
		}
	}
	
	/*エネミーのUpDate*/
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)  //エネミーが存在する時
		{
			enemy[enemyCount]->Update(); //エネミーと弾を動かす
			if (720 < enemy[enemyCount]->GetLocation().y - 30)  //エネミーが画面外に行った時
			{   //エネミーを消す
				delete enemy[enemyCount];
				enemy[enemyCount] = nullptr;
				break;
			}

			//タイプが打ち返しで、HPが0のエネミー
			if ((enemy[enemyCount]->GetEnemyType() == ENEMY_TYPE::REPEL) && 
				(enemy[enemyCount]->HpCheck()))
			{
				BulletsBase** bullet;
				bullet = enemy[enemyCount]->GetBullets();
				//弾が存在しない時
				if (bullet[0] == nullptr)
				{
					//エネミーを消す
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;
				}
			}
		}
	}
	
	/*アイテムのUpDate*/
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (drop_item[itemCount] != nullptr)  //アイテムが存在する時
		{
			drop_item[itemCount]->Update();
			if (drop_item[itemCount]->GetLocation().y - 5 > 720) //エネミーが画面外に行った時
			{
				//アイテムを消す
				delete drop_item[itemCount];
				drop_item[itemCount] = nullptr;
			}
		}
	}

	//弾やアイテムの当たり判定
	HitCheck();

	//プレイヤーが死亡して３秒たった時GameOverシーンに遷移
	if (playerDie)
	{
		if(180 <= ++secenWaitTime) return new GameOver();
	}

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
					{   //アイテムの生成
						for (int itemCount = 0; itemCount < 10; itemCount++)
						{
							//エネミータイプが打ち返し以外の時、アイテムを生成する
							if (drop_item[itemCount] == nullptr && enemy[enemyCount]->GetEnemyType() != ENEMY_TYPE::REPEL)
							{
								srand((unsigned int)time(NULL));
								drop_item[itemCount] = new DropItem(enemy[enemyCount]->GetLocation(), 5, rand() % 5, 0.8f);
								break;
							}
						}
						//エネミータイプが打ち返し以外の時
						if (enemy[enemyCount]->GetEnemyType()!= ENEMY_TYPE::REPEL)
						{
							//エネミーを消す
							delete enemy[enemyCount];
							enemy[enemyCount] = nullptr;
						}
						else //エネミータイプが打ち返しの時
						{
							enemy[enemyCount]->RepelMaterialization();
						}
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
				//プレイヤーのHPが０になったか
				if (player->LifeCheck())
				{
					playerDie = true;  //プレイヤーの生死フラグをtrueにする
				}
			}
		}
	}

	/*アイテムとプレイヤーの当たり判定*/
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{   //アイテムが存在するか
		if (drop_item[itemCount] == nullptr) continue;

		//プレイヤーがアイテムに当たったか
		if (drop_item[itemCount]->HitSphere(player->GetLocation(), player->GetRadius()))
		{   //アイテムの効果をプレイヤーに反映する
			player->Hit(drop_item[itemCount]->GetType(), drop_item[itemCount]->GetEffects(static_cast<int>(drop_item[itemCount]->GetType())));
			delete drop_item[itemCount];
			drop_item[itemCount] = nullptr;
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

	if(player != nullptr) player->Draw();

	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)
		{
			enemy[enemyCount]->Draw();
		}
	}
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (drop_item[itemCount] != nullptr)  //アイテムが存在する時
		{
			drop_item[itemCount]->Draw();
		}
	}

	DrawString(1000, 0, "escキーで終わる",0xffffff);
}