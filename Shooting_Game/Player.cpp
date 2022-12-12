#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#include "common.h"

Player::Player()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる
	location.x = static_cast<float>(x);
	location.y = static_cast<float>(y);
	life = 10;
	radius = 10;
	score = 0;
	shotCount = 0;
	upDamage = 0;
	bullets = new BulletsBase * [MAX_SHOT];
	for (int i = 0; i < MAX_SHOT; i++)
	{
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	GetMousePoint(&x, &y);   //マウスの座標を自機の座標に入れる
	location.x = static_cast<float>(x);
	location.y = static_cast<float>(y);
	//自機が画面外に行かないようにする
	if (location.x < 0) location.x = 0.f;
	else if (location.x > 1280) location.x = 1280.f;
	if (location.y < 0) location.y = 0.f;
	else if (location.y > 720) location.y = 720.f;

	int bulletcount = 0;
	
	//空いている弾を探す
	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] == nullptr)
		{
			break;
		}
	}

	if ((shotCount % 5) == 0 && (KeyInput::OnPressed(MOUSE_INPUT_LEFT)))
	{
		bullets[bulletcount] = new BulletStraight(location.x, location.y,-5.f,5,upDamage);
	}

	for (bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			bullets[bulletcount]->Update();  //弾を動かす
			if (bullets[bulletcount]->GetLocation().y < 0)  //弾が上の画面外に行ったら消す
			{
				DeleteBullet(bulletcount);
			}
		}
	}

	++shotCount;
}

void Player::Hit(int damage)
{
	life -= damage;
}

void Player::Hit(ITEM_TYPE item, int effects)
{
	if (item == ITEM_TYPE::HEAL)  //HPを回復する
	{
		life += effects;
	}
	if (item == ITEM_TYPE::ATTACK) //攻撃力を上げる
	{
		upDamage += effects;
		for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
		{
			if (bullets[bulletcount] != nullptr)
			{
				bullets[bulletcount]->UpDamage(effects);
			}
		}
	}
}

void Player::LifeCheck()
{

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
	DrawString(0, 0, "プレイヤー", 0x00ff00);
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