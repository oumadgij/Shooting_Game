#pragma once
#include "AbstractScene.h"
class GameClear : public AbstractScene
{
public:
	//�R���X�g���N�^
	GameClear();
	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;

private:
};

