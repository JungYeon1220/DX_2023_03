#include "framework.h"
#include "TutorialScene.h"
#include "../../Object/Obj/Player.h"

TutorialScene::TutorialScene()
{
	_player = make_shared<Player>();
	_rect = make_shared<RectCollider>(Vector2(1000.0f, 500.0f));
	_rect->GetTransform()->SetPosition(Vector2(CENTER.x, 0.0f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_player->Update();
	_rect->Update();

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
}
