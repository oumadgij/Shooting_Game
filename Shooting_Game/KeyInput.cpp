#include "KeyInput.h"
#include "DxLib.h"

int KeyInput::nowMouse;
int KeyInput::oldMouse;
int KeyInput::nowKey;
int KeyInput::oldKey;

void KeyInput::Update()
{
	oldKey = nowKey;
	nowKey = GetJoypadInputState(DX_INPUT_KEY);

	oldMouse = nowMouse;
	nowMouse = GetMouseInput();
}