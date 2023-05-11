#include "framework.h"
#include "Maze.h"
#include <map>
#include <queue>

Maze::Maze()
{
	Vector2 offset = Vector2(400, 100);

	_blocks.resize(25);
	for (int y = 0; y < _poolCountY; y++) // y����� �����
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

	CreateMaze_Prim();
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
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->SetType(MazeBlock::BlockType::DISABLE);
		}
	}

	// ��� �ձ�
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	for (int y = 0; y < _poolCountY; y++) // y����� �����
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			// ������ �������� ó��
			if (x == _poolCountX - 2 && y == _poolCountY - 2)
				continue;

			// ������ ���� �� �շ��ְ�
			if (x == _poolCountX - 2)
			{
				_blocks[y + 1][x]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			// �Ʒ��� ���� �� �շ��ְ�
			if (y == _poolCountY - 2)
			{
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			// ������ Ȥ�� �Ʒ��� �������� ���� �մ� �۾�
			const int randValue = rand() % 2;
			if (randValue == 0)
				_blocks[y][x + 1]->SetType(MazeBlock::BlockType::ABLE);
			else
				_blocks[y + 1][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	_blocks[_poolCountX - 2][_poolCountY - 2]->SetType(MazeBlock::BlockType::END);
}

void Maze::CreateMaze_Kruskal()
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->SetType(MazeBlock::BlockType::DISABLE);
		}
	}

	// ��� �ձ�
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (x < _poolCountX - 2)
			{
				const int randValue = rand() % 100;
				Edge_Kruskal edge;
				edge.u = Vector2(x, y);
				edge.v = Vector2(x + 2, y);
				edge.cost = randValue;
				edges.push_back(edge);
			}

			if (y < _poolCountY - 2)
			{
				const int randValue = rand() % 100;
				Edge_Kruskal edge;
				edge.u = Vector2(x, y);
				edge.v = Vector2(x, y + 2);
				edge.cost = randValue;
				edges.push_back(edge);
			}
		}
	}

	std::sort(edges.begin(), edges.end(), [](const Edge_Kruskal& a, const Edge_Kruskal& b)->bool
	{
		return a.cost < b.cost;
	});

	DisJointSet sets(_poolCountX * _poolCountY);

	for (const auto& edge : edges)
	{
		int u = edge.u.y * _poolCountX + edge.u.x;
		int v = edge.v.y * _poolCountX + edge.v.x;
		if (sets.FindLeader(u) == sets.FindLeader(v))
			continue;

		sets.Merge(u, v);
		int yIndex = (edge.u.y + edge.v.y) / 2;
		int xIndex = (edge.u.x + edge.v.x) / 2;
		_blocks[yIndex][xIndex]->SetType(MazeBlock::BlockType::ABLE);
	}
}

void Maze::CreateMaze_Prim()
{
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			_blocks[y][x]->SetType(MazeBlock::BlockType::DISABLE);
		}
	}

	// ��� �ձ�
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	map<Vector2, vector<Edge>> edges;

	// ��� ������ �ĺ��� ��Ƶδ� �۾�
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (x < _poolCountX - 2)
			{
				const int randValue = rand() % 100;
				Vector2 u = { x, y };
				Vector2 v = { x + 2, y };
				edges[u].push_back({ randValue, v });
				edges[v].push_back({ randValue, u });
			}

			if (y < _poolCountY - 2)
			{
				const int randValue = rand() % 100;
				Vector2 u = { x, y };
				Vector2 v = { x, y + 2 };
				edges[u].push_back({ randValue, v });
				edges[v].push_back({ randValue, u });
			}
		}
	}

	// �ش� ������ ���տ� ���ԵǾ��ֳ�
	map<Vector2, bool> added;

	// � ������ ������ ���� ���� �Ǿ��ִ���
	map<Vector2, Vector2> parent;

	// ����� �ִ� ���տ� ������ ���� �� �ش� ������ ��� �ּ� ������ ����
	map<Vector2, int> best;

	// added, best �ʱ�ȭ
	for (int y = 0; y < _poolCountY; y++)
	{
		for (int x = 0; x < _poolCountX; x++)
		{
			best[Vector2(x, y)] = INT_MAX;
			added[Vector2(x, y)] = false;
		}
	}

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	Vector2 startPos = StartPos();
	pq.push({ 0, startPos });
	best[startPos] = 0;
	parent[startPos] = startPos;

	while (true)
	{
		if (pq.empty())
			break;

		Edge bestEdge = pq.top();
		pq.pop();

		// ���� ����� ����
		Vector2 vertex = bestEdge.v;

		if (added[vertex])
			continue;

		added[vertex] = true;

		// �ʿ� ����
		{
			int x = (parent[vertex].x + vertex.x) / 2;
			int y = (parent[vertex].y + vertex.y) / 2;

			_blocks[y][x]->SetType(MazeBlock::BlockType::ABLE);
		}

		for (Edge& edge : edges[vertex])
		{
			if (added[edge.v])
				continue;

			// �ٸ� ��η� �� ���� �ĺ��� �߰��� �Ǿ��־����� ��ŵ
			if (edge.cost > best[edge.v])
				continue;

			best[edge.v] = edge.cost;
			parent[edge.v] = vertex;
			pq.push(edge);
		}
	}

	return;
}
