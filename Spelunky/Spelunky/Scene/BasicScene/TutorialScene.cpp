#include "framework.h"
#include "TutorialScene.h"
#include "../../Object/Obj/Player.h"
#include "../../Object/Obj/Tile.h"

TutorialScene::TutorialScene()
{
	_player = make_shared<Player>();
	_tile = make_shared<Tile>();
	_tile->SetPosition(Vector2(_tile->GetSize(), 205.0f));
	_tile->SetType(Tile::Type::LADDER);

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<Tile> tile = make_shared<Tile>();
		tile->SetPosition(Vector2((i + 0.5f) * tile->GetSize()  , 105.0f));
		tile->SetType(Tile::Type::NORMAL);

		_tiles.push_back(tile);
	}
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	bool check = false;
	for (auto tile : _tiles)
	{
		if (tile->Block(_player->GetCollider()))
		{
			check = true;
		}
		tile->Update();
	}

	if (_tile->Block(_player->GetCollider()))
		check = true;

	if (check == false)
	{
		_player->IsFalling() = true;
	}
	else
	{
		_player->IsFalling() = false;
	}

	_tile->Update();
	_player->Update();
}

void TutorialScene::Render()
{
	_player->Render();
	for (auto tile : _tiles)
	{
		tile->Render();
	}
	_tile->Render();
}

void TutorialScene::PostRender()
{
	_player->PostRender();
}
