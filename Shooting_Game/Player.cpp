#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#include "common.h"

Player::Player()
{
	GetMousePoint(&x, &y);   //�}�E�X�̍��W�����@�̍��W�ɓ����
	location.x = static_cast<float>(x);
	location.y = static_cast<float>(y);
	life = 0;
	radius = 10;
	score = 0;
	shotCount = 0;
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

	if ((shotCount % 5) == 0 && (KeyInput::OnPressed(MOUSE_INPUT_LEFT)))
	{
		bullets[bulletcount] = new BulletStraight(location.x, location.y,-5.f,5);
	}

	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();  //�e�𓮂���
			if (bullets[bulletcount]->GetLocation().y < 0)  //�e����̉�ʊO�ɍs���������
			{
				delete bullets[bulletcount];
				bullets[bulletcount] = nullptr;
			}
		}
	}

	++shotCount;
}

void Player::Hit(int damage)
{

}

void Player::LifeCheck()
{

}

void Player::Draw()const
{
#define DEBUG
#ifdef DEBUG
#endif // DEBUG


	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(225, 0, 0), TRUE);

	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Draw();
		}
	}
}