#pragma once
class KeyInput
{
public:
	static void Update();
	static bool OnPressed(int inputkey)
	{
		bool ret = (nowKey & inputkey);
		return ret;
	}

private:
	KeyInput() = default;

	static int oldKey;   //�O��̓��̓L�[
	static int nowKey;   //����̓��̓L�[
	//int keyFlg;   //���̓L�[���
};

