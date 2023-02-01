#include "KeyInput.h"
#include "DxLib.h"

int KeyInput::nowMouse;
int KeyInput::oldMouse;
void KeyInput::Update()
{
	oldMouse = nowMouse;
	nowMouse = GetMouseInput();
}