#include "GameMain.h"

GameMain::GameMain()
{
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = 0;
	}
}

AbstractScene* GameMain::Update()
{
	player.Update();
	return this;
}

void GameMain::HitCheck()
{

}

void GameMain::Draw() const
{
	player.Draw();
}