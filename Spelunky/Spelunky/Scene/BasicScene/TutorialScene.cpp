#include "framework.h"
#include "TutorialScene.h"
#include "../../Object/Obj/Player.h"

TutorialScene::TutorialScene()
{
	_player = make_shared<Player>();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_player->Update();
}

void TutorialScene::Render()
{
	_player->Render();
}
