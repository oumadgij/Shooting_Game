#pragma once
class CharaBase
{
public:
	//�f�X�g���N�^
	virtual ~CharaBase() {};
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	//�����蔻��
	virtual void Hit() = 0;

	int* GetBullets()const { return this->bullets[0]; }

private:
	int* bullets[10];  //�e�@���u�� TO DO
	int speed;
	
protected:
	int image;
};