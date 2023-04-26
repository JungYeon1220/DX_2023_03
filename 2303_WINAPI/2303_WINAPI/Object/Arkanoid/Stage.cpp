#include "framework.h"
#include "Stage.h"

Stage::Stage()
{
	_bricks.resize(_poolCountY);
	for (int y = 0; y < _poolCountY; y++)
	{
		_bricks[y].reserve(_poolCountX);
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<Brick> brick = make_shared<Brick>();
			brick->SetPosition(_offSet + Vector2(BRICKSIZEX * x + 1, BRICKSIZEY * y + 1));

			_bricks[y].push_back(brick);
		}
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	for (auto brickArr : _bricks)
	{
		for (auto brick : brickArr)
		{
			brick->Update();
		}
	}
}

void Stage::Render(HDC hdc)
{
	for (auto brickArr : _bricks)
	{
		for (auto brick : brickArr)
		{
			brick->Render(hdc);
		}
	}
}
