#pragma once
class KeyInput
{
public:
	static void Update();
	static bool OnPressed(int inputkey) //マウスがクリックされているか
	{
		bool ret = (nowKey & inputkey);
		return ret;
	}

private:
	KeyInput() = default;

	static int oldKey;   //前回の入力キー
	static int nowKey;   //今回の入力キー
	//int keyFlg;   //入力キー情報
};

