#include "GameOver.h"
#include "KeyInput.h"
#include "DxLib.h"
#include "Title.h"

GameOver::GameOver()
{

}

AbstractScene* GameOver::Update()
{
	if (KeyInput::OnClick(MOUSE_INPUT_LEFT))
	{
		return new Title();
	}

	return this;
}

void GameOver::Draw()const
{
	DrawString(300, 400, "  Game Over  ", 0xff00ff);
	DrawString(300, 500, "左クリックでタイトルに戻る", 0xff00ff);
}