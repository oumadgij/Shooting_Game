#pragma once
class KeyInput
{
public:
	static void Update();
	static bool OnPressed(int inputmouse) //�}�E�X���N���b�N����Ă��邩
	{
		bool ret = (nowMouse & inputmouse);
		return ret;
	}
	//�{�^�����������u�Ԃ����𔻒�
	static bool OnClick(int inputKey)
	{
		int keyFlag = nowKey & ~oldKey;
		bool ret = (keyFlag & inputKey);
		return ret;
	}

private:
	KeyInput() = default;

	static int oldMouse;   //�O��̓��̓L�[(�}�E�X)
	static int nowMouse;   //����̓��̓L�[(�}�E�X)
	static int oldKey;     //�O��̓��̓L�[(�L�[�{�[�h)
	static int nowKey;     //����̓��̓L�[(�L�[�{�[�h)
};

