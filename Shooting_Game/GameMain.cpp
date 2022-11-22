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
		if (enemy[i] == nullptr) break;
	}

	return this;
}

void GameMain::HitCheck()
{

}

void GameMain::Draw() const
{
	player->Draw();
}