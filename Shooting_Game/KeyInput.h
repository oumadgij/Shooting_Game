#pragma once
class KeyInput
{
public:
	void Update();

private:
	KeyInput() = default;

	static int oldKey;   //�O��̓��̓L�[
	static int nowKey;   //����̓��̓L�[
	int keyFlg;   //���̓L�[���
};

