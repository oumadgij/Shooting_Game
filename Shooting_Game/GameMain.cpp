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
	//�G�l�~�[�����݂��Ă��邩�ǂ���
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
	//		if (enemy[enemyCount]->GetLocation().y > 720)  //�G�l�~�[����ʊO�ɍs������
	//		{
	//			delete enemy[enemyCount];
	//			enemy[enemyCount] = nullptr;
	//		}
	//	}
	//}
	if (enemy[0] != nullptr)
	{
		enemy[0]->Update();
		if (enemy[0]->GetLocation().y > 720)  //�G�l�~�[����ʊO�ɍs������
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
	/*�v���C���[�̒e�ƃG�l�~�[�̓����蔻��*/
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{	
		//�G�l�~�[�����݂��鎞
		if (enemy[enemyCount] != nullptr)
		{
			for (int bulletCount = 0; bulletCount < 30; bulletCount++)
			{
				//�e�����݂��鎞
				if (bullet[bulletCount] != nullptr)
				{
					//�v���C���[�̒e���G�l�~�[�ɂ���������
					if (enemy[enemyCount]->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
					{
						//����������
						enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());  //�G�l�~�[�Ƀ_���[�W��^����
						delete bullet[bulletCount];   //�e������
						bullet[bulletCount] = nullptr;
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