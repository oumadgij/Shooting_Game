#pragma once
#include "AbstractScene.h"
class GameOver :public AbstractScene
{
public:
	//�R���X�g���N�^
	GameOver();
	//�`��ȊO�̍X�V������
	virtual AbstractScene* Update()override;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw() const override;
};
