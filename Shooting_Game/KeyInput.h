#pragma once
class KeyInput
{
public:
	static void Update();
	static bool OnPressed(int inputmouse) //マウスがクリックされているか
	{
		bool ret = (nowMouse & inputmouse);
		return ret;
	}
	//ボタンを押した瞬間だけを判定
	static bool OnClick(int inputKey)
	{
		int keyFlag = nowMouse & ~oldMouse;
		bool ret = (keyFlag & inputKey);
		return ret;
	}

private:
	KeyInput() = default;

	static int oldMouse;   //前回の入力キー(マウス)
	static int nowMouse;   //今回の入力キー(マウス)
};

