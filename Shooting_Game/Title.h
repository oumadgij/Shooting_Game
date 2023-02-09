#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Title :public AbstractScene
{
public:
	//�R���X�g���N�^
	Title();
	//�f�X�g���N�^
	~Title() 
	{ 
		DeleteFontToHandle(englishFont); 
		DeleteFontToHandle(japaneseFont);
	}
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
private:
	int englishFont; //�p��p�t�H���g
	int japaneseFont; //���{��p�t�H���g
};

