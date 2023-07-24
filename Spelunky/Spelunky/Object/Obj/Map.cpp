#include "framework.h"
#include "Map.h"
#include "Tile/Tile.h"

Map::Map()
{
	_tileMap.resize(_poolCountY);
	for (int i = 0; i < _poolCountY; i++)
	{
		_tileMap[i].reserve(_poolCountX);
		for (int j = 0; j < _poolCountX; j++)
		{
			shared_ptr<Tile> tile = make_shared<Tile>();
			tile->SetPosition(Vector2(100.0f * j, 100.0f * i) - CENTER);

			if (i < 2 || i > _poolCountY - 2 || j < 2 || j > _poolCountX)
				tile->SetType(Tile::Type::UNBREAKABLE);
			else
				tile->SetType(Tile::Type::EMPTY);

			_tileMap[i].push_back(tile);
		}
	}
}

Map::~Map()
{
}

void Map::Update()
{
	for (auto tileArr : _tileMap)
	{
		for (auto tile : tileArr)
			tile->Update();
	}
}

void Map::Render()
{
	for (auto tileArr : _tileMap)
	{
		for (auto tile : tileArr)
			tile->Render();
	}
}

void Map::CreateTiles()
{
}
