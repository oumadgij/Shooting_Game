#include "Boss.h"
#include "common.h"
#include "BulletStraight.h"
#include "BulletVLine.h"

Boss::Boss(float Vx, float Vy, float r)
{
	hp = 10;
	radius = r;
	point = 0;
	speed = 1.0f;
	location.x = Vx;
	location.y = Vy;
	shotCount = 0;
	waittime = 0;
	nowIndex = 0;
	bullets = new BulletsBase * [BOSS_MAX_SHOT];
	for (int i = 0; i < ENEMY_MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
	
	/*CSV�t�@�C���̓ǂݍ���*/
	InputCSV();
}

void Boss::Update()
{
	int bulletcount = 0;
	//�e�����݂��邩���Ȃ������ׂ�
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)  //���݂��Ȃ����Ƀ��[�v�𔲂���
		{
			break;
		}
	}

	if (50 <= ++shotCount)
	{
		//�e�̎��̉�
		if (moveinfo[nowIndex].attacktype == 1)
		{
			bullets[bulletcount] = new BulletStraight(location.x, location.y, 6.f, 10, 0);
		}
		if (moveinfo[nowIndex].attacktype == 2)
		{
			bullets[bulletcount] = new BulletVLine(location.x, location.y, 6.f, 10, 85, 0);
			bullets[bulletcount + 1] = new BulletVLine(location.x, location.y, 5.f, 10, 95, 0);
		}

		shotCount = 0;
	}

	switch (moveinfo[nowIndex].pattern)
	{
	case 0:
		Move();
		break;
	case 1:
		waittime++;
		if (moveinfo[nowIndex].waittime <= waittime)
		{
			waittime = 0;
			nowIndex = moveinfo[nowIndex].next;
		}
		break;
	}

	//�e�𓮂���
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();
			if (bullets[bulletcount]->GetLocation().y > 720) //�e�����̉�ʊO�ɍs������
			{
				//��ʊO�ɍs�����Ƃ��e������
				DeleteBullet(bulletcount);
			}
		}
	}
}

void Boss::Draw()const
{
#define DEBUG
#ifdef DEBUG
	DrawFormatString(800, 100, 0xffffff,"pattern�F%d", moveinfo[nowIndex].pattern);
	DrawFormatString(800, 200, 0xffffff,"�ړI�n X�F%f Y�F%f", moveinfo[nowIndex].destination.x, moveinfo[nowIndex].destination.y);
	DrawFormatString(800, 300, 0xffffff, "���݂̍��W X�F % f Y�F % f", location.x, location.y);
#endif // DEBUG

	//�{�X�̕\��
	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x4b0082, TRUE);

	//�e�̕\��
	for (int bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), 0xFFB400, TRUE);
		}
	}
}

void Boss::Hit(int damage)
{

}

void Boss::Move()
{
	//�{�X�̍��W���ړI�n�ɂ������ǂ���
	if ((location.x == moveinfo[nowIndex].destination.x)
		&& (location.y == moveinfo[nowIndex].destination.y))
	{
		//�ړI�n�ɂ����� �Y������ς���
		nowIndex = moveinfo[nowIndex].next;
	}
	else
	{   //�ړI�n�ɂ��Ă��Ȃ�������

		//�ړI�n��x���W���{�X��x���W���傫���Ƃ�
		if (location.x < moveinfo[nowIndex].destination.x)
		{
			location.x += speed;
		}
		//�ړI�n��x���W���{�X��x���W��菬�����Ƃ�
		else
		{
			location.x -= speed;
		}

		//�ړI�n��y���W���{�X��y���W���傫���Ƃ�
		if (location.y < moveinfo[nowIndex].destination.y)
		{
			location.y += speed;
		}
		//�ړI�n��y���W���{�X��y���W��菬�����Ƃ�
		else
		{
			location.y -= speed;
		}
	}
}

void Boss::InputCSV()
{
	FILE* fp;
	errno_t error = fopen_s(&fp, "data/Boss.txt", "r");
	if (error != 0)
	{
		//�t�@�C�����J���Ȃ�����
		//throw "�t�@�C���ǂݍ��݃G���[\n";
		return;
	}
	else
	{
		//�t�@�C�����J����
		char line[100];
		for (int i = 0; fgets(line, 100, fp) != NULL; i++)
		{
			sscanf_s(line, "%d,%f,%f,%d,%d,%d", &moveinfo[i].pattern, &moveinfo[i].destination.x, &moveinfo[i].destination.y, &moveinfo[i].next, &moveinfo[i].waittime, &moveinfo[i].attacktype);
		}
	}

	printf("%d", error);
	fclose(fp);
}

void Boss::DeleteBullet(int bulletcount)
{
	delete bullets[bulletcount];
	bullets[bulletcount] = nullptr;
}