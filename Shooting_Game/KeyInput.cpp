#include "KeyInput.h"
#include "DxLib.h"

int KeyInput::nowKey;
int KeyInput::oldKey;

void KeyInput::Update()
{
	oldKey = nowKey;
	nowKey = GetMouseInput();
	//keyFlg = nowKey&~oldKey;  //ê‡‚É‚æ‚Á‚Ä‚±‚±‚Í‚¢‚ç‚È‚¢
}