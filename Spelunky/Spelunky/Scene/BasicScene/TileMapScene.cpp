#include "framework.h"
#include "TileMapScene.h"
#include "../../Object/Obj/Tile.h"

TileMapScene::TileMapScene()
{
	_tileMap.resize(_poolCountY);
	for (int y = 0; y < _poolCountY; y++)
	{
		_tileMap[y].reserve(_poolCountX);
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<Tile> tile = make_shared<Tile>();
			float size = tile->GetSize();
			tile->SetPosition(_offSet + Vector2(size * x, size * y));
			tile->TileSelect(Tile::Type::EMPTY);

			_tileMap[y].push_back(tile);
		}
	}
}

TileMapScene::~TileMapScene()
{
}

void TileMapScene::Update()
{
	for (auto tileArr : _tileMap)
	{
		for (auto tile : tileArr)
			tile->Update();
	}
}

void TileMapScene::Render()
{
	for (auto tileArr : _tileMap)
	{
		for (auto tile : tileArr)
			tile->Render();
	}
}
