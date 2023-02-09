#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Title :public AbstractScene
{
public:
	//コンストラクタ
	Title();
	//デストラクタ
	~Title() 
	{ 
		DeleteFontToHandle(englishFont); 
		DeleteFontToHandle(japaneseFont);
	}
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
private:
	int englishFont; //英語用フォント
	int japaneseFont; //日本語用フォント
};

