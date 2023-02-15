#pragma once
#include "AbstractScene.h"
class GameOver :public AbstractScene
{
public:
	//コンストラクタ
	GameOver();
	//描画以外の更新を実装
	virtual AbstractScene* Update()override;
	//描画に関することを実装
	virtual void Draw() const override;
};

