#include "DxLib.h"
#include "SceneManager.h"
#include "GameMain.h"
#include "KeyInput.h"
#include "common.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("シューティングゲーム");

	ChangeWindowMode(TRUE);           //ウィンドウモードで起動
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);         //画面サイズの変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 16);      //画面モードの変更
	if (DxLib_Init() == -1) return -1;   //DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);     //描画先画面を裏に設定

	SetMouseDispFlag(FALSE);     //マウスカーソルの表示 TRUE:表示する FALSE:表示しない 

	SceneManager sceneMng(new GameMain());   //シーンをゲームメインに設定

	while ((ProcessMessage()==0) && (sceneMng.Update() != nullptr) && (!KeyInput::OnClick(PAD_INPUT_9)))
	{
		ClearDrawScreen();    //画面の初期化
		KeyInput::Update();
		sceneMng.Draw();

		//if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) SetMouseDispFlag(TRUE);  //マウスカーソルを表示する

		ScreenFlip();   //裏画面の内容を表画面に反映
	}

	DxLib_End();    //DXライブラリ終了処理
	return 0;
}