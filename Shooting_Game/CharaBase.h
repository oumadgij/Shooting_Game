#pragma once
class CharaBase
{
public:
	//コンストラクタ
	CharaBase();
	//デストラクタ
	virtual ~CharaBase() {};
	//描画以外の更新を実装
	virtual void Update() = 0;
	//描画に関することを実装
	virtual void Draw()const = 0;
	//当たり判定
	virtual void Hit() = 0;

	int* GetBullets()const { return this->bullets[0]; }
	
protected:
	int image;
	int* bullets[10];  //弾　仮置き TO DO
	int speed;
};