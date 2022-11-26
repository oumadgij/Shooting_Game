#include "GameMain.h"
#include "DxLib.h"

GameMain::GameMain()
{
	player = new Player;
	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = nullptr;
	}
	item = new ItemBase * [10];
	for (int i = 0; i < 10; i++)
	{
		item[i] = nullptr;
	}
}

AbstractScene* GameMain::Update()
{
	player->Update();
	for (int i = 0; i < 10; i++)
	{
		if (enemy[i] == nullptr)
		{
			enemy[i] = new Enemy(500, 0.f);
		}
	}

	enemy[0]->Update();
	if (enemy[0]->GetY() > 720)
	{
		delete enemy[0];
		enemy[0] = nullptr;
	}

	return this;
}

void GameMain::HitCheck()
{

}

void GameMain::Draw() const
{
	player->Draw();
	if (enemy[0] != nullptr)
	{
		enemy[0]->Draw();
	}
}