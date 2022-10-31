#pragma once

class BulletsBase
{
public:
	//�R���X�g���N�^
	BulletsBase();
	//�f�X�g���N�^
	virtual ~BulletsBase() {};
	//�`��ȊO�̍X�V������
	virtual void Update() = 0;
	//�`��Ɋւ��邱�Ƃ�����
	virtual void Draw()const = 0;
	void SetBulletsX(int x) { bulletx = x; }
	void SetBulletsY(int y) { bullety = y; }
	void ChangeShotFlg() { shotflg = !shotflg; }
	int GetDamage()const { return damage; }
	int GetBulletsX()const { return bulletx; }
	int GetBulletsY()const { return bullety; }
	bool GetShotFlg()const { return shotflg; }

protected:
	int damage;   //�_���[�W
	int speed;    //�X�s�[�h
	int bulletx, bullety;     //X���W,Y���W
	bool shotflg; //���˒����ǂ��� true:���˒� false:���˒��ł͂Ȃ�
};