#include "GameMain.h"
#include "DxLib.h"
#include "common.h"
#include <time.h>
#include "GameOver.h"
#include "GameClear.h"

GameMain::GameMain()
{
	player = new Player;
	boss = nullptr;
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
	bossAppearanceTime = 0;
	playerDie = false;
}

AbstractScene* GameMain::Update()
{
	player->Update();

	/*�{�X�̎��̉�*/
	//�Q�[�����n�܂���1�����������{�X�����̉�������
	if ((boss == nullptr)&&(3600 < ++bossAppearanceTime))
	{
		boss = new Boss(560.f, -10.f, 60);
		bossAppearanceTime = 0;
	}

	int enemyCount;

	/*�G�l�~�[�̑��݂𒲂ׂ�*/
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr) break;
	}
	/*�{�X�ȊO�̓G�����Ȃ��Ȃ�܂Ń{�X�͓������Ȃ�*/
	if ((boss != nullptr)&& (enemyCount == 10))
	{
		boss->Update();

		//�{�X��HP��0�ɂȂ�����
		if (boss->HpCheck())
		{
			return new GameClear();
		}
	}

	/*�G�l�~�[�̎��̉�*/
	if (++waittime < 100 == 0)
	{
		for (enemyCount = 0; enemyCount < 10; enemyCount++)
		{
			//�G�l�~�[�����݂��Ȃ������{�X�����݂��Ȃ���
			if ((enemy[enemyCount] == nullptr) && (boss == nullptr))
			{   //�����_���ʒu�ɃG�l�~�[��z�u����
				enemy[enemyCount] = new Enemy(static_cast<float>(rand() % WINDOW_WIDTH-50)+30, 0.f, 30);
				//�G�l�~�[�̃^�C�v�������_���Ɍ��肷��
				//0:�X�g���[�g 1:v���C�� 2:�ł��Ԃ� 3:�������Ȃ�
				enemy[enemyCount]->SelectType(rand() % 4);
				break;
			}
		}
		waittime = 0;
	}
	
	/*�G�l�~�[��UpDate*/
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)  //�G�l�~�[�����݂��鎞
		{
			enemy[enemyCount]->Update(); //�G�l�~�[�ƒe�𓮂���
			if (720 < enemy[enemyCount]->GetLocation().y - 30)  //�G�l�~�[����ʊO�ɍs������
			{   //�G�l�~�[������
				delete enemy[enemyCount];
				enemy[enemyCount] = nullptr;
				break;
			}

			//�^�C�v���ł��Ԃ��ŁAHP��0�̃G�l�~�[
			if ((enemy[enemyCount]->GetEnemyType() == ENEMY_TYPE::REPEL) && 
				(enemy[enemyCount]->HpCheck()))
			{
				BulletsBase** bullet;
				bullet = enemy[enemyCount]->GetBullets();
				//�e�����݂��Ȃ���
				if (bullet[0] == nullptr)
				{
					//�G�l�~�[������
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;
				}
			}
		}
	}
	
	/*�A�C�e����UpDate*/
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (drop_item[itemCount] != nullptr)  //�A�C�e�������݂��鎞
		{
			drop_item[itemCount]->Update();
			if (drop_item[itemCount]->GetLocation().y - 5 > 720) //�G�l�~�[����ʊO�ɍs������
			{
				//�A�C�e��������
				delete drop_item[itemCount];
				drop_item[itemCount] = nullptr;
			}
		}
	}

	/*�e��A�C�e���̓����蔻��*/
	HitCheck();

	/*�v���C���[�����S���ĂR�b��������GameOver�V�[���ɑJ��*/
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
					//�v���C���[�̒e���G�l�~�[�ɓ���������
					if (enemy[enemyCount]->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
					{
						if (!enemy[enemyCount]->HpCheck())//���񂾃G�l�~�[�ɒe��������̂�h��
						{
							//�G�l�~�[��HP�����炷
							enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());
							player->DeleteBullet(bulletCount);  //�e������
						}
					}
					//�G�l�~�[��HP���O�ɂȂ�����
					if (enemy[enemyCount]->HpCheck())
					{   //�A�C�e���̐���
						for (int itemCount = 0; itemCount < 10; itemCount++)
						{
							//�G�l�~�[�^�C�v���ł��Ԃ��ȊO�̎��A�A�C�e���𐶐�����
							if (drop_item[itemCount] == nullptr && enemy[enemyCount]->GetEnemyType() != ENEMY_TYPE::REPEL)
							{
								srand((unsigned int)time(NULL));
								drop_item[itemCount] = new DropItem(enemy[enemyCount]->GetLocation(), 5, rand() % 5, 0.8f);
								break;
							}
						}
						//�G�l�~�[�^�C�v���ł��Ԃ��ȊO�̎�
						if (enemy[enemyCount]->GetEnemyType()!= ENEMY_TYPE::REPEL)
						{
							//�G�l�~�[������
							delete enemy[enemyCount];
							enemy[enemyCount] = nullptr;
						}
						else //�G�l�~�[�^�C�v���ł��Ԃ��̎�
						{
							enemy[enemyCount]->RepelMaterialization();
						}
						break;
					}
				}
			}
		}
	}

	/*�v���C���[�̒e�ƃ{�X�̓����蔻��*/
	//�{�X�����݂��鎞
	if (boss != nullptr)
	{
		for (int bulletCount = 0; bulletCount < MAX_SHOT; bulletCount++)
		{
			//�e�����݂��鎞
			if (bullet[bulletCount] != nullptr)
			{
				//�v���C���[�̒e���{�X�ɂ���������
				if (boss->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
				{
					//����������
					boss->Hit(bullet[bulletCount]->GetDamage());  //�{�X��HP�����炷
					player->DeleteBullet(bulletCount);  //�e������
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
				//�v���C���[��HP���O�ɂȂ�����
				if (player->LifeCheck())
				{
					playerDie = true;  //�v���C���[�̐����t���O��true�ɂ���
				}
			}
		}
	}

	/*�{�X�̒e�ƃv���C���[�̓����蔻��*/
	//�{�X�����݂��邩�ǂ���
	if (boss != nullptr)
	{
		bullet = boss->GetBullets();

		for (int bulletCount = 0; bulletCount < ENEMY_MAX_SHOT; bulletCount++)
		{
			//�e�����݂��鎞
			if (bullet[bulletCount] != nullptr)
			{   //�G�l�~�[�̒e���v���C���[�ɓ���������
				if (player->HitSphere(bullet[bulletCount]->GetLocation(), bullet[bulletCount]->GetRadius()))
				{
					//����������
					player->Hit(bullet[bulletCount]->GetDamage());  //�v���C���[��HP�����炷
					boss->DeleteBullet(bulletCount); //�e������
				}
				//�v���C���[��HP���O�ɂȂ�����
				if (player->LifeCheck())
				{
					playerDie = true;  //�v���C���[�̐����t���O��true�ɂ���
				}
			}
		}
	}

	/*�A�C�e���ƃv���C���[�̓����蔻��*/
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{   //�A�C�e�������݂��邩
		if (drop_item[itemCount] == nullptr) continue;

		//�v���C���[���A�C�e���ɓ���������
		if (drop_item[itemCount]->HitSphere(player->GetLocation(), player->GetRadius()))
		{   //�A�C�e���̌��ʂ��v���C���[�ɔ��f����
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

	if (boss != nullptr) DrawFormatString(0, 120, 0xffffff, "Boss: %2d", boss->GetHP());
	DrawFormatString(0, 500, 0xffffff, "Boss�o������: %2d", bossAppearanceTime);
#endif // DEBUG

	//�v���C���[�̕`��
	if(player != nullptr) player->Draw();
	
	//�G�̕`��
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] != nullptr)
		{
			enemy[enemyCount]->Draw();
		}
	}

	//�{�X�̕`��
	if(boss != nullptr) boss->Draw();

	//�A�C�e���̕`��
	for (int itemCount = 0; itemCount < 10; itemCount++)
	{
		if (drop_item[itemCount] != nullptr)  //�A�C�e�������݂��鎞
		{
			drop_item[itemCount]->Draw();
		}
	}

	DrawString(1000, 0, "esc�L�[�ŏI���",0xffffff);
}