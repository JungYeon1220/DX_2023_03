#include "framework.h"
#include "SpriteScene.h"

#include "../../Object/Obj/Zelda/Zelda.h"

SpriteScene::SpriteScene()
{
	_zelda = make_shared<Zelda>();
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_zelda->Update();
}

void SpriteScene::Render()
{
	_zelda->Render();
}

void SpriteScene::PostRender()
{
}
