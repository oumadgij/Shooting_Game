#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#include "BulletVLine.h"
#include "BulletComposite.h"
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
	interval = 4;
	comparison = 0;
	bulletLine = 0;
	bulletType = BULLET_TYPE::COMPOSITE;
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

	//shotCount��attackInterval�̒��̐��l���傫���Ȃ������}�E�X�̍����������ꂽ��
	//�e�����̉�
	if ((attackInterval[interval] <= ++shotCount) && (KeyInput::OnPressed(MOUSE_INPUT_LEFT)))
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
		{   //�e�����݂��鎞�U���͂��グ��
			if (bullets[bulletcount] != nullptr)
			{
				bullets[bulletcount]->UpDamage(effects);
				if ((5 <= bullets[bulletcount]->GetDamage()) && //�U���͂��T�ȏォ��
					(bulletType == BULLET_TYPE::STRAIGHT)) //�e�̃^�C�v���X�g���[�g�̎�
				{
					bulletLine = 2;
				}
				//�e�̔��ˊԊu�̒���
				//�_���[�W���z��̒��̐��������傫��������A���ˊԊu�����߂�
				if (damageComparison[comparison] <= bullets[bulletcount]->GetDamage())
				{
					if (--interval <= 0)interval = 0;
					++comparison;
					break;
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
	if (bulletType == BULLET_TYPE::STRAIGHT)
	{

		bullets[bulletcount] = new BulletStraight(location.x, location.y, -5.f, 5, upDamage);
	}
	/*   �@V�@���@   */
	if (bulletType == BULLET_TYPE::VLINE)
	{
		bullets[bulletcount] = new BulletVLine(location.x, location.y, -5.f, 5, 85);
		bullets[bulletcount+1] = new BulletVLine(location.x, location.y, -5.f, 5, 95);
	}
	/* V���ƃX�g���[�g�����̂������� */
	if (bulletType == BULLET_TYPE::COMPOSITE)
	{
		bullets[bulletcount] = new BulletComposite(location.x, location.y, -5.f, 5, 80, upDamage);
		bullets[bulletcount+1] = new BulletComposite(location.x, location.y, -5.f, 5, 90, upDamage);
		bullets[bulletcount+2] = new BulletComposite(location.x, location.y, -5.f, 5, 100, upDamage);
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
	DrawFormatString(0, 30, 0xffffff, "Player Life : %d", life);
	DrawString(0, 60, "�e�̎�� :", 0xffffff);
	/*if (bulletType == BULLET_TYPE::STRAIGHT)
	{
		DrawString(90, 60, "�X�g���[�g", 0xffffff);
	}
	else if (bulletType == BULLET_TYPE::VLINE)
	{
		DrawString(90, 60, "V��", 0xffffff);
	}*/
	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++) //�e�̍U����
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawFormatString(0 + bulletcount * 60, 60, 0xffffff, "%d = %d", bulletcount,bullets[bulletcount]->GetDamage());
		}
	}
	DrawFormatString(0, 90, 0xffffff, "Interval : %d", attackInterval[interval]);
#endif // DEBUG


	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(225, 0, 0), TRUE);

	//�e�̕`��
	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), GetColor(100, 180, 0), TRUE);
		}
	}
}