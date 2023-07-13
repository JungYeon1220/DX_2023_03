#include "framework.h"
#include "TutorialScene.h"
#include "../../Object/Obj/Player.h"
#include "../../Object/Obj/Tile.h"

TutorialScene::TutorialScene()
{
	_player = make_shared<Player>();

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<Tile> tile = make_shared<Tile>();
		tile->SetPosition(Vector2((i + 0.5f) * tile->GetSize()  , 105.0f));
		tile->TileSelect(Tile::Type::NORMAL);

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
		if (tile->GetCollider()->Block(_player->GetCollider()))
		{
			check = true;
		}
		tile->Update();
	}

	if (check == false)
	{
		_player->IsFalling() = true;
	}
	else
	{
		_player->IsFalling() = false;
	}

	_player->Update();
}

void TutorialScene::Render()
{
	_player->Render();
	for (auto tile : _tiles)
	{
		tile->Render();
	}
}
