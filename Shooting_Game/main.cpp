#include "DxLib.h"
#include "SceneManager.h"
#include "GameMain.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�V���[�e�B���O�Q�[��");

	ChangeWindowMode(TRUE);           //�E�B���h�E���[�h�ŋN��
	if (DxLib_Init() == -1) return -1;   //DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);     //�`����ʂ𗠂ɐݒ�

	SceneManager sceneMng(new GameMain());   //�V�[�����Q�[�����C���ɐݒ�

	while ((ProcessMessage()==0) && (sceneMng.Update() != nullptr))
	{
		ClearDrawScreen();    //��ʂ̏�����

		sceneMng.Draw();

		ScreenFlip();   //����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();    //DX���C�u�����I������
	return 0;
}