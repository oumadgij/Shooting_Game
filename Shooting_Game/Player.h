#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"
#include "DropItem.h"

enum class BULLET_TYPE
{
	STRAIGHT,   //ストレート
	VLINE,      //V字
	COMPOSITE   //V字とストレートの複合
};

class Player : public CharaBase,public SphereCollider
{
public:
	//コンストラクタ
	Player();
	//描画以外の更新を実装
	virtual void Update()override;
	//描画に関することを実装
	virtual void Draw()const override;
	//当たり判定
	virtual void Hit(int damage)override;  //弾に当たった時の処理
	void Hit(ITEM_TYPE item,int effects);  //アイテムに当たった時の処理
	bool LifeCheck();  //HPが０になったかどうか ture:０になった false:０でない
	void DeleteBullet(int bulletcount);
	int GetScore()const { return score; }

private:
	void BulletSelect(int bulletcount);  //弾の種類を選ぶ
	int x, y;    //座標
	int score;   //スコア
	int life;    //HP
	int shotCount;//攻撃間隔
	int upDamage; //攻撃力の増加量
	int bulletLine;  //弾が出る列   TODO １列から２列に増やそうとして作った変数。まだ処理を作っていない
	int interval;   //attackIntervalの添え字
	int dComparison = 0; //damageComparison[]の添え字
	int bComparison = 0; //bulletComparison[]の添え字
	const int attackInterval[5] = { 6,12,18,24,30 };  //弾を出す速さ
	const int damageComparison[5] = { 5,10,15,20,25 };  //弾の射出速度を変更するための攻撃力の目安
	const int bulletComparison[2] = { 13,18 };   //弾の種類を変更するための攻撃力の目安
	BULLET_TYPE bulletType;
};

