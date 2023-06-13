#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"Resource/Testure/zelda.png", Vector2(10, 8));
	_transform = make_shared<Transform>();
	_transform->SetPosition(CENTER);

	_sprite->SetCurFrame(Vector2(0, 1));
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_transform->Update();
	_sprite->Update();
}

void SpriteScene::Render()
{
	_transform->SetWorldBuffer(0);
	_sprite->Render();
}
