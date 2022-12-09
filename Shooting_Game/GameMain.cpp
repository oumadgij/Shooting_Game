#include "GameMain.h"
#include "DxLib.h"
#include "common.h"
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
	waittime = 0;
}

AbstractScene* GameMain::Update()
{
	player->Update();
	int enemyCount;
	//�G�l�~�[�����݂��Ă��邩�ǂ���
	if (++waittime % 100 == 0)
	{
		for (enemyCount = 0; enemyCount < 10; enemyCount++)
		{
			if (enemy[enemyCount] == nullptr)
			{
				enemy[enemyCount] = new Enemy(static_cast<float>(rand() % WINDOW_WIDTH-50)+30, 0.f, 30);
				waittime = 0;
				break;
			}
		}
	}
	
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)
		{
			enemy[enemyCount]->Update();
			if (enemy[enemyCount]->GetLocation().y-30 > 720)  //�G�l�~�[����ʊO�ɍs������
			{
				delete enemy[enemyCount];
				enemy[enemyCount] = nullptr;
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
	/*�v���C���[�̒e�ƃG�l�~�[�̓����蔻��*/
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		//�G�l�~�[�����݂��鎞
		if (enemy[enemyCount] != nullptr)
		{
			for (int bulletCount = 0; bulletCount < MAX_SHOT; bulletCount++)
			{
				//�e�����݂��鎞
				if (bullet[bulletCount] != nullptr)
				{
					//�v���C���[�̒e���G�l�~�[�ɂ���������
					if (enemy[enemyCount]->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
					{
						//����������
						enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());  //�G�l�~�[��HP�����炷
						player->DeleteBullet(bulletCount);  //�e������
					}
					//�G�l�~�[��HP���O�ɂȂ�����
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

	/*�G�l�~�[�̒e�ƃv���C���[�̓����蔻��*/
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{   //�G�l�~�[�����݂��邩�ǂ���
		if (enemy[enemyCount] == nullptr) break;
		bullet = enemy[enemyCount]->GetBullets();

		for (int bulletCount = 0; bulletCount < ENEMY_MAX_SHOT; bulletCount++)
		{
			//�e�����݂��鎞
			if (bullet[bulletCount] != nullptr)
			{   //�G�l�~�[�̒e���v���C���[�ɓ���������
				if (player->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
				{
					//����������
					player->Hit(bullet[bulletCount]->GetDamage());  //�v���C���[��HP�����炷
					enemy[enemyCount]->DeleteBullet(bulletCount); //�e������
				}
			}
		}
	}
}

void GameMain::Draw() const
{
#define DEBUG
#ifdef DEBUG
	DrawString(0, 100, "�G�l�~�[", 0xff0000);
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

	/*if (enemy[0] != nullptr)
	{
		enemy[0]->Draw();
	}*/
}