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
	//�e�����݂��邩���Ȃ������ׂ�
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)  //���݂��Ȃ����Ƀ��[�v�𔲂���
		{
			break;
		}
	}

	if (++shotCount % 120 == 0)
	{
		//�e�̎��̉�
		if (eType == ENEMY_TYPE::STRAIGHT)  //�X�g���[�g
		{
			bullets[bulletcount] = new BulletStraight(location.x, location.y + 25, 5.f, 10, 0);
		}
		if (eType == ENEMY_TYPE::VLINE)     //V��
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
		eType = ENEMY_TYPE::STRAIGHT;  //�X�g���[�g
		break;
	case 1:
		eType = ENEMY_TYPE::VLINE;     //V��
		break;
	case 2:
		eType = ENEMY_TYPE::REPEL;     //�ł��Ԃ�
		break;
	case 3:
		eType = ENEMY_TYPE::DEFAULT;   //�������Ȃ�
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

	//HP��0���傫�����\������
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
		if (eType == ENEMY_TYPE::REPEL)     //�ł��Ԃ�
		{
			bullets[0] = new BulletStraight(location.x, location.y, 5.f, 10, 0);
		}
	}
}