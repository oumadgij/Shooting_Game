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
	
	/*CSVファイルの読み込み*/
	InputCSV();
}

void Boss::Update()
{
	int bulletcount = 0;
	//弾が存在するかしないか調べる
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)  //存在しない時にループを抜ける
		{
			break;
		}
	}

	if (50 <= ++shotCount)
	{
		//弾の実体化
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

	//弾を動かす
	for (bulletcount = 0; bulletcount < ENEMY_MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();
			if (bullets[bulletcount]->GetLocation().y > 720) //弾が下の画面外に行ったか
			{
				//画面外に行ったとき弾を消す
				DeleteBullet(bulletcount);
			}
		}
	}
}

void Boss::Draw()const
{
#define DEBUG
#ifdef DEBUG
	DrawFormatString(800, 100, 0xffffff,"pattern：%d", moveinfo[nowIndex].pattern);
	DrawFormatString(800, 200, 0xffffff,"目的地 X：%f Y：%f", moveinfo[nowIndex].destination.x, moveinfo[nowIndex].destination.y);
	DrawFormatString(800, 300, 0xffffff, "現在の座標 X： % f Y： % f", location.x, location.y);
#endif // DEBUG

	//ボスの表示
	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), 0x4b0082, TRUE);

	//弾の表示
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
	//ボスの座標が目的地についたかどうか
	if ((location.x == moveinfo[nowIndex].destination.x)
		&& (location.y == moveinfo[nowIndex].destination.y))
	{
		//目的地についたら 添え字を変える
		nowIndex = moveinfo[nowIndex].next;
	}
	else
	{   //目的地についていなかったら

		//目的地のx座標がボスのx座標より大きいとき
		if (location.x < moveinfo[nowIndex].destination.x)
		{
			location.x += speed;
		}
		//目的地のx座標がボスのx座標より小さいとき
		else
		{
			location.x -= speed;
		}

		//目的地のy座標がボスのy座標より大きいとき
		if (location.y < moveinfo[nowIndex].destination.y)
		{
			location.y += speed;
		}
		//目的地のy座標がボスのy座標より小さいとき
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
		//ファイルが開けなかった
		//throw "ファイル読み込みエラー\n";
		return;
	}
	else
	{
		//ファイルが開けた
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