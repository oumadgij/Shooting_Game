#pragma once
class KeyInput
{
public:
	void Update();

private:
	KeyInput() = default;

	static int oldKey;   //前回の入力キー
	static int nowKey;   //今回の入力キー
	int keyFlg;   //入力キー情報
};

