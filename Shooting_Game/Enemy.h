#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

enum class ENEMY_TYPE
{
	STRAIGHT,   //ストレート
	VLINE,      //V字
	REPEL,      //打ち返し
	DEFAULT     //何もしない
};

class Enemy : public CharaBase, public SphereCollider
{
public:
	//コンストラクタ
	Enemy(float Vx,float Vy,float r);  //(x座標,y座標,半径)
	//描画以外の更新を実装
	virtual void Update() override;
	//描画に関することを実装
	virtual void Draw() const override;
	//当たり判定
	virtual void Hit(int damage) override;
	//エネミーを動かす
	void Move();
	//敵の動きタイプを選ぶ
	void SelectType(int type);
	//Hpが0か
	bool HpCheck();
	//弾を消す
	void DeleteBullet(int bulletcount);
	//打ち返しの弾の実体化
	void RepelMaterialization();
	//ゲッター
	int GetPoint()const { return point; }
	int GetHP()const { return hp; }
	ENEMY_TYPE GetEnemyType()const { return eType; }

private:
	int hp;
	int point;
	int shotCount;
	ENEMY_TYPE eType;
};

