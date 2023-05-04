#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	Vector2 offset = Vector2(400, 100);

	_blocks.resize(25);
	for (int y = 0; y < _poolCountY; y++) // y축부터 만든다
	{
		_blocks[y].reserve(25);
		for (int x = 0; x < _poolCountX; x++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();
			block->SetPosition(offset + Vector2(18 * x, 18 * y));
			block->SetType(MazeBlock::BlockType::DISABLE);

			_blocks[y].push_back(block);
		}
	}

	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blockArr : _blocks)
	{
		for (auto block : blockArr)
			block->Update();
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blockArr : _blocks)
	{
		for (auto block : blockArr)
			block->Render(hdc);
	}
}

void Maze::CreateMaze()
{

	// 노드 뚫기
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	for (int y = 0; y < _poolCountY; y++) // y축부터 만든다
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// 마지막 도착지점 처리
			if (x == _poolCountX - 2 && y == _poolCountY - 2)
				continue;

			// 오른쪽 끝는 다 뚫려있게
			if (x == _poolCountX - 2)
			{
				_blocks[y + 1][x]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			// 아래쪽 끝은 다 뚫려있게
			if (y == _poolCountY - 2)
			{
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			// 오른쪽 혹은 아래쪽 랜덤으로 길을 뚫는 작업
			const int randValue = rand() % 2;
			if (randValue == 0)
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
			else
				_blocks[y + 1][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}


	_blocks[_poolCountX - 2][_poolCountY - 2]->SetType(MazeBlock::BlockType::END);
}
