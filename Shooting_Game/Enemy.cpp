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
	//�e�����݂��邩���Ȃ������ׂ�
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)  //���݂��Ȃ����Ƀ��[�v�𔲂���
		{
			break;
		}
	}

	if (120 < ++shotCount)
	{
		//�e�̎��̉�
		if (enemyType == ENEMY_TYPE::STRAIGHT)  //�X�g���[�g
		{
			bullets[bulletcount] = new BulletStraight(location.x, location.y + 25, 5.f, 5, 0);  //radius ��10  TODO
		}
		if (enemyType == ENEMY_TYPE::VLINE)     //V��
		{
			bullets[bulletcount] = new BulletVLine(location.x, location.y, 5.f, 5, 85,0);  //radius ��10  TODO
			bullets[bulletcount + 1] = new BulletVLine(location.x, location.y, 5.f, 5, 95,0);  //radius ��10  TODO
		}
		shotCount = 0;
	}

	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();//�e�𓮂���
			if (bullets[bulletcount]->GetLocation().y > 720) //�e�����̉�ʊO�ɍs������
			{
				//��ʊO�ɍs�����Ƃ��e������
				DeleteBullet(bulletcount);
			}
		}
	}
}

/*�G�l�~�[�𓮂���*/
void Enemy::Move()
{
	location.y += speed;
}

/*�G�̓����^�C�v��I��*/
void Enemy::SelectType(int type)
{
	switch (type)
	{
	case 0:
		enemyType = ENEMY_TYPE::STRAIGHT;  //�X�g���[�g
		break;
	case 1:
		enemyType = ENEMY_TYPE::VLINE;     //V��
		break;
	case 2:
		enemyType = ENEMY_TYPE::REPEL;     //�ł��Ԃ�
		break;
	case 3:
		enemyType = ENEMY_TYPE::DEFAULT;   //�������Ȃ�
		break;
	}
}

/*�����蔻��*/
void Enemy::Hit(int damage)
{
	hp -= damage;
}

/*HP���O�ȉ����`�F�b�N����*/
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

	//HP��0���傫�����G��\������
	if (hp > 0)
	{
		//�X�g���[�g�Œe�����G�̐F ��
		if (enemyType == ENEMY_TYPE::STRAIGHT)
		{
			DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x0064C5, TRUE);
		}
		//V���Œe�����G�̐F ��
		if (enemyType == ENEMY_TYPE::VLINE)
		{
			DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x008E69, TRUE);
		}
		//���񂾂Ƃ��ɒe���o���G�̐F �s���N
		if (enemyType == ENEMY_TYPE::REPEL)
		{
			DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0xD5648D, TRUE);
		}
	}
	
	//�e�̕\��
	for (int bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), 0xFFB400, TRUE);
		}
	}
}

/*�e������*/
void Enemy::DeleteBullet(int bulletcount)
{
	delete bullets[bulletcount];
	bullets[bulletcount] = nullptr;
}

/*�ł��Ԃ��̒e�̎��̉�*/
void Enemy::RepelMaterialization()
{
	if (bullets[0] == nullptr)
	{
		if (enemyType == ENEMY_TYPE::REPEL)     //�ł��Ԃ�
		{
			bullets[0] = new BulletStraight(location.x, location.y, 5.f, 10, 0);
		}
	}
}