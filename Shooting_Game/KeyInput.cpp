#include "KeyInput.h"
#include "DxLib.h"

int KeyInput::nowKey;
int KeyInput::oldKey;

void KeyInput::Update()
{
	oldKey = nowKey;
	nowKey = GetMouseInput();
	//keyFlg = nowKey&~oldKey;  //場合によってここはいらない
}