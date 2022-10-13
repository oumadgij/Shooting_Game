#include "KeyInput.h"
#include "DxLib.h"

int KeyInput::nowKey;
int KeyInput::oldKey;

void KeyInput::Update()
{
	oldKey = nowKey;
	nowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	keyFlg = nowKey&~oldKey;  //èÍçáÇ…ÇÊÇ¡ÇƒÇ±Ç±ÇÕÇ¢ÇÁÇ»Ç¢
}