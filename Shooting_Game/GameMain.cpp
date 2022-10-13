#include "GameMain.h"

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