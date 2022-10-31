#pragma once

class BulletsBase
{
public:
	//コンストラクタ
	BulletsBase();
	//デストラクタ
	virtual ~BulletsBase() {};
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	void SetBulletsX(int x) { bulletx = x; }
	void SetBulletsY(int y) { bullety = y; }
	void ChangeShotFlg() { shotflg = !shotflg; }
	int GetDamage()const { return damage; }
	int GetBulletsX()const { return bulletx; }
	int GetBulletsY()const { return bullety; }
	bool GetShotFlg()const { return shotflg; }

protected:
	int damage;   //ダメージ
	int speed;    //スピード
	int bulletx, bullety;     //X座標,Y座標
	bool shotflg; //発射中かどうか true:発射中 false:発射中ではない
};