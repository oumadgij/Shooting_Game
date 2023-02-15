#pragma once
#include "CharaBase.h"
#include "SphereCollider.h"

struct actionInfo
{
	int pattern;  //行動パターン
	VECTOR destination; //目的地
	int next;  //次の配列番号
	int waittime; //待ち時間
	int attacktype;  //攻撃の種類
};

class Boss :public CharaBase,public SphereCollider
{
public:
	//コンストラクタ
	Boss(float Vx, float Vy, float r);  //(x座標,y座標,半径)
	//描画以外の更新を実装
	virtual void Update() override;
	//描画に関することを実装
	virtual void Draw() const override;
	//当たり判定
	virtual void Hit(int damage) override;
	//ボスを動かす
	void Move();
	//CSVファイル読み込み
	void InputCSV();
	//弾を消す
	void DeleteBullet(int bulletcount);
	//Hpが0か調べる
	bool HpCheck();
	int GetHP()const { return hp; }

private:
	int hp;
	int point;
	int shotCount;   //弾が出る早さ
	int waittime;    //次の行動に移るまでの待ち時間
	int nowIndex;    //現在の添え字

	actionInfo moveinfo[4];
};

