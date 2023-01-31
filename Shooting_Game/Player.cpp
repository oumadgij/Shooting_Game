#include "Player.h"
#include "KeyInput.h"
#include "BulletStraight.h"
#include "BulletVLine.h"
#include "BulletComposite.h"
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

	//shotCountがattackIntervalの中の数値より大きくなった＆マウスの左側を押されたら
	//弾を実体化
	if ((attackInterval[interval] <= ++shotCount) && (KeyInput::OnPressed(MOUSE_INPUT_LEFT)))
	{
		BulletSelect(bulletcount);
		shotCount = 0;
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
}

void Player::Hit(int damage)
{
	life -= damage;
}

void Player::Hit(ITEM_TYPE item, int effects)
{
	if (item == ITEM_TYPE::HEAL)  //HPを回復する
	{
		if ((life += effects) >= 10)//HPの上限を超えないようにする
		{
			life = 10;
		}
	}
	if (item == ITEM_TYPE::ATTACK) //攻撃力を上げる
	{
		upDamage += effects;
		for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
		{   //弾が存在する時攻撃力を上げる
			if (bullets[bulletcount] != nullptr)
			{
				bullets[bulletcount]->UpDamage(effects);
				if ((5 <= bullets[bulletcount]->GetDamage()) && //攻撃力が５以上かつ
					(bulletType == BULLET_TYPE::STRAIGHT)) //弾のタイプがストレートの時
				{
					bulletLine = 2;
				}
				//弾の発射間隔の調整
				//ダメージが配列の中の数字よりも大きかったら、発射間隔を狭める
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
{   /*   ストレート   */
	if (bulletType == BULLET_TYPE::STRAIGHT)
	{

		bullets[bulletcount] = new BulletStraight(location.x, location.y, -5.f, 5, upDamage);
	}
	/*   　V　字　   */
	if (bulletType == BULLET_TYPE::VLINE)
	{
		bullets[bulletcount] = new BulletVLine(location.x, location.y, -5.f, 5, 85);
		bullets[bulletcount+1] = new BulletVLine(location.x, location.y, -5.f, 5, 95);
	}
	/* V字とストレートを合体したもの */
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
	DrawString(0, 0, "プレイヤー", 0x00ff00);
	DrawFormatString(0, 30, 0xffffff, "Player Life : %d", life);
	DrawString(0, 60, "弾の種類 :", 0xffffff);
	/*if (bulletType == BULLET_TYPE::STRAIGHT)
	{
		DrawString(90, 60, "ストレート", 0xffffff);
	}
	else if (bulletType == BULLET_TYPE::VLINE)
	{
		DrawString(90, 60, "V字", 0xffffff);
	}*/
	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++) //弾の攻撃力
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawFormatString(0 + bulletcount * 60, 60, 0xffffff, "%d = %d", bulletcount,bullets[bulletcount]->GetDamage());
		}
	}
	DrawFormatString(0, 90, 0xffffff, "Interval : %d", attackInterval[interval]);
#endif // DEBUG


	DrawCircle(static_cast<int>(location.x), static_cast<int>(location.y), static_cast<int>(radius), GetColor(225, 0, 0), TRUE);

	//弾の描画
	for (int bulletcount = 0; bulletcount < MAX_SHOT; bulletcount++)
	{
		if (bullets[bulletcount] != nullptr)
		{
			DrawCircle(static_cast<int>(bullets[bulletcount]->GetLocation().x), static_cast<int>(bullets[bulletcount]->GetLocation().y), static_cast<int>(bullets[bulletcount]->GetRadius()), GetColor(100, 180, 0), TRUE);
		}
	}
}