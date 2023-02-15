#include "GameClear.h"
#include "KeyInput.h"
#include "DxLib.h"
#include "Title.h"

GameClear::GameClear()
{

}

AbstractScene* GameClear::Update()
{
	if (KeyInput::OnClick(MOUSE_INPUT_LEFT))
	{
		return new Title();
	}

	return this;
}

void GameClear::Draw()const
{
	DrawString(300, 400, "  Game Clear!  ", 0xff00ff);
	DrawString(300, 500, "���N���b�N�Ń^�C�g���ɖ߂�", 0xff00ff);
}
