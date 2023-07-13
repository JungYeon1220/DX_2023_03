#include "framework.h"
#include "TutorialScene.h"
#include "../../Object/Obj/Player.h"
#include "../../Object/Obj/Tile.h"

TutorialScene::TutorialScene()
{
	_player = make_shared<Player>();
	_rect = make_shared<RectCollider>(Vector2(1000.0f, 500.0f));
	_tile = make_shared<Tile>();
	_rect->GetTransform()->SetPosition(Vector2(CENTER.x, 0.0f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_player->Update();
	_rect->Update();
	_tile->Update();

	if (_rect->Block(_player->GetCollider()))
	{
		_player->IsFalling() = false;
	}
	else
	{
		_player->IsFalling() = true;
	}
}

void TutorialScene::Render()
{
	_rect->Render();
	_player->Render();
	_tile->Render();
}
