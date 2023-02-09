#include "Title.h"
#include "KeyInput.h"
#include "GameMain.h"
#include "common.h"

Title::Title()
{
	englishFont = CreateFontToHandle("HARDCORE POSTER", 80, -1, DX_FONTTYPE_NORMAL);
	japaneseFont = CreateFontToHandle("MS UI Gothic", 60, -1, DX_FONTTYPE_NORMAL);
}

AbstractScene* Title::Update()
{
	if (KeyInput::OnClick(MOUSE_INPUT_LEFT))
	{
		return new GameMain();
	}

	return this;
}

void Title::Draw()const
{
	DrawFormatStringToHandle(WINDOW_WIDTH/5, 80, 0xffffff, englishFont, "Shooting Game");
	DrawFormatStringToHandle(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2, 0xff0000, japaneseFont, "左クリックでゲームスタート");
}