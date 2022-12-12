#include "DxLib.h"
#include "SceneManager.h"
#include "GameMain.h"
#include "KeyInput.h"
#include "common.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("�V���[�e�B���O�Q�[��");

	ChangeWindowMode(TRUE);           //�E�B���h�E���[�h�ŋN��
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);         //��ʃT�C�Y�̕ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);      //��ʃ��[�h�̕ύX
	if (DxLib_Init() == -1) return -1;   //DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);     //�`����ʂ𗠂ɐݒ�

	SetMouseDispFlag(FALSE);     //�}�E�X�J�[�\���̕\�� TRUE:�\������ FALSE:�\�����Ȃ� 

	SceneManager sceneMng(new GameMain());   //�V�[�����Q�[�����C���ɐݒ�

	while ((ProcessMessage()==0) && (sceneMng.Update() != nullptr) && (!KeyInput::OnClick(PAD_INPUT_9)))
	{
		ClearDrawScreen();    //��ʂ̏�����
		KeyInput::Update();
		sceneMng.Draw();

		//if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) SetMouseDispFlag(TRUE);  //�}�E�X�J�[�\����\������

		ScreenFlip();   //����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();    //DX���C�u�����I������
	return 0;
}