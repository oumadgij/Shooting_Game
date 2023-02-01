#include "Title.h"
#include "KeyInput.h"
#include "GameMain.h"
#include "DxLib.h"

Title::Title()
{

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
	DrawString(300, 450, "���N���b�N�ŃQ�[���X�^�[�g", 0xff0000);
}