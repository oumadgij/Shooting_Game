#include "DxLib.h"
#include "SceneManager.h"
#include "GameMain.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("シューティングゲーム");

	ChangeWindowMode(TRUE);           //ウィンドウモードで起動
	if (DxLib_Init() == -1) return -1;   //DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);     //描画先画面を裏に設定

	SceneManager sceneMng(new GameMain());   //シーンをゲームメインに設定

	while ((ProcessMessage()==0) && (sceneMng.Update() != nullptr))
	{
		ClearDrawScreen();    //画面の初期化

		sceneMng.Draw();

		ScreenFlip();   //裏画面の内容を表画面に反映
	}

	DxLib_End();    //DXライブラリ終了処理
	return 0;
}