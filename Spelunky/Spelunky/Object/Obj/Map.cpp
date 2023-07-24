#include "framework.h"
#include "Map.h"
#include "Tile/Tile.h"
#include "Tiles.h"

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

			tile->SetType(Tile::Type::EMPTY);
			if (i < 2 || i > _poolCountY - 3 || j < 2 || j > _poolCountX - 3)
				tile->SetType(Tile::Type::UNBREAKABLE);

			_tileMap[i].push_back(tile);
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (road[i][j] == 1)
				_tileMap[9 - i][j + 2]->SetType(Tile::Type::NORMAL);
			if(road[i][j] == 3)
				_tileMap[9 - i][j + 2]->SetType(Tile::Type::ONE_WAY);
		}
	}
}

Map::~Map()
{
}

void Map::Update()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (_tileMap[i][j]->GetType() == Tile::Type::NORMAL)
			{

			}
		}
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
