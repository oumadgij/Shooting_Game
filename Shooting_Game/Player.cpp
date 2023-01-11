#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#include "BulletVLine.h"
#include "common.h"

Player::Player()
{
	GetMousePoint(&x, &y);   //�}�E�X�̍��W�����@�̍��W�ɓ����
	location.x = static_cast<float>(x);
	location.y = static_cast<float>(y);
	life = 10;
	radius = 10;
	score = 0;
	shotCount = 0;
	upDamage = 0;
	bulletLine = 0;
	bType = BULLET_TYPE::STRAIGHT;
	bullets = new BulletsBase * [MAX_SHOT];
	for (int i = 0; i < MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	GetMousePoint(&x, &y);   //�}�E�X�̍��W�����@�̍��W�ɓ����
	location.x = static_cast<float>(x);
	location.y = static_cast<float>(y);
	//���@����ʊO�ɍs���Ȃ��悤�ɂ���
	if (location.x < 0) location.x = 0.f;
	else if (location.x > 1280) location.x = 1280.f;
	if (location.y < 0) location.y = 0.f;
	else if (location.y > 720) location.y = 720.f;

	int bulletcount = 0;
	
	//�󂢂Ă���e��T��
	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if ((++shotCount % 5) == 0 && (KeyInput::OnPressed(MOUSE_INPUT_LEFT)))
	{
		BulletSelect(bulletcount);
		shotCount = 0;
	}

	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();  //�e�𓮂���
			if (bullets[bulletcount]->GetLocation().y < 0)  //�e����̉�ʊO�ɍs���������
			{
				DeleteBullet(bulletcount);
			}
		}
	}
}

void Player::Hit(int damage)
{
	life -= damage;
}

void Player::Hit(ITEM_TYPE item, int effects)
{
	if (item == ITEM_TYPE::HEAL)  //HP���񕜂���
	{
		if ((life += effects) >= 10)//HP�̏���𒴂��Ȃ��悤�ɂ���
		{
			life = 10;
		}
	}
	if (item == ITEM_TYPE::ATTACK) //�U���͂��グ��
	{
		upDamage += effects;
		for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
		{
			if (bullets[bulletcount] != nullptr)
			{
				bullets[bulletcount]->UpDamage(effects);
				if (bullets[bulletcount]->GetDamage()>=5) //�U���͂��T�ȏ�̎�
				{
					bulletLine = 2;
					//DeleteBullet(bulletcount); 
				}
			}
		}
	}
}

bool Player::LifeCheck()
{
	if (life <= 0)
	{
		return true;
	}

	return false;
}

void Player::BulletSelect(int bulletcount)
{   /*   �X�g���[�g   */
	if (bType == BULLET_TYPE::STRAIGHT)
	{

		bullets[bulletcount] = new BulletStraight(location.x, location.y, -5.f, 5, upDamage);
	}
	if (bType == BULLET_TYPE::VLINE)
	{
		bullets[bulletcount] = new BulletVLine(location.x, location.y, -5.f, 5, 85);
		bullets[bulletcount+1] = new BulletVLine(location.x, location.y, -5.f, 5, 95);
	}
}

void Player::DeleteBullet(int bulletcount)
{
	delete bullets[bulletcount];
	bullets[bulletcount] = nullptr;
}

void Player::Draw()const
{
#define DEBUG
#ifdef DEBUG
	DrawString(0, 0, "�v���C���[", 0x00ff00);
	DrawFormatString(0, 30, 0xffffff, "Player Life = %d", life);
	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawFormatString(0 + bulletcount * 60, 60, 0xffffff, "%d = %d", bulletcount,bullets[bulletcount]->GetDamage());
		}
	}
#endif // DEBUG


	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(225, 0, 0), TRUE);

	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), GetColor(100, 180, 0), TRUE);
		}
	}
}