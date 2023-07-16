#include "framework.h"
#include "TileMapScene.h"
#include "../../Object/Obj/Tile.h"
#include "../../Object/Obj/Player.h"

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
			tile->SetPosition(_offSet + Vector2(size * x, size * y) - CENTER);
			tile->SetType(Tile::Type::EMPTY);

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
		{
			if (tile->GetCollider()->IsCollision(W_MOUSE_POS))
			{
				if (KEY_DOWN(VK_LBUTTON))
				{
					if (tile->GetType() == Tile::Type::EMPTY)
						tile->SetType(Tile::Type::NORMAL);
					else if (tile->GetType() == Tile::Type::NORMAL)
						tile->SetType(Tile::Type::EMPTY);
				}
				tile->GetCollider()->SetRed();
			}
			else
			{
				tile->GetCollider()->SetGreen();
			}

			tile->Update();
		}
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

void TileMapScene::PostRender()
{
}
