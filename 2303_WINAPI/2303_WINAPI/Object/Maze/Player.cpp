#include "framework.h"
#include "Player.h"
#include <stack>
#include <queue>

Player::Player(shared_ptr<Maze> maze)
	: _maze(maze)
{
	if (_maze.expired() == false)
	{
		_startPos = _maze.lock()->StartPos();
		_endPos = _maze.lock()->EndPos();
		_maze.lock()->Block(_startPos.x, _startPos.y)->SetType(MazeBlock::BlockType::PLAYER);
	}

	Dijkstra();
}

Player::~Player()
{
}

void Player::Update()
{
	_time += 0.2f;
	if (_time > 1.0f)
	{
		_time = 0.0f;
		_visitedIndex++;
		if (_visitedIndex >= _visited.size())
		{
			_pathIndex++;
		}
	}

	if (_visitedIndex >= _visited.size())
	{
		if (_pathIndex >= _path.size())
		{
			return;
		}

		Vector2 temp = _path[_pathIndex];
		_maze.lock()->Block(temp.x, temp.y)->SetType(MazeBlock::BlockType::PLAYER);

		if (_pathIndex != 0)
		{
			Vector2 temp2 = _path[_pathIndex - 1];
			_maze.lock()->Block(temp2.x, temp2.y)->SetType(MazeBlock::BlockType::PATH);
		}
	}
	else if(_visited.empty() == false)
	{
		Vector2 temp = _visited[_visitedIndex];
		_maze.lock()->Block(temp.x, temp.y)->SetType(MazeBlock::BlockType::PLAYER);

		if (_visitedIndex != 0)
		{
			Vector2 temp2 = _visited[_visitedIndex - 1];
			_maze.lock()->Block(temp2.x, temp2.y)->SetType(MazeBlock::BlockType::VISITED);
		}
	}
}

bool Player::Cango(Vector2 pos)
{
	MazeBlock::BlockType type = _maze.lock()->Block(pos.x, pos.y)->GetType();
	if (type == MazeBlock::BlockType::DISABLE)
		return false;
	if (type == MazeBlock::BlockType::NONE)
		return false;

	return true;
}

void Player::RightHand()
{
	Vector2 pos = _startPos;
	_path.push_back(pos);

	Dir curDir = Dir::DIR_UP;

	Vector2 frontPos[4] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0} // RIGHT
	};

	while (true)
	{
		if (pos == _endPos)
			break;

		int newDir = (curDir - 1 + Dir::DIR_COUNT) % Dir::DIR_COUNT;
		Vector2 oldDirVector = frontPos[curDir]; // 기존 방향
		Vector2 newDirVector = frontPos[newDir]; // 새로운 방향 (시계방향)

		// 현재 바라보는 방향에서 오른쪽 손을 짚었을 때 갈 수 있는 곳인지 확인
		if (Cango(pos + newDirVector))
		{
			curDir = static_cast<Dir>(newDir);
			pos += newDirVector;
			_maze.lock()->Block(pos.x, pos.y)->SetType(MazeBlock::BlockType::VISITED);
			_path.push_back(pos);
		}

		// 현재 바라보는 방향으로 전진할 수 있는지 확인
		else if (Cango(pos + oldDirVector))
		{
			pos += oldDirVector;
			_maze.lock()->Block(pos.x, pos.y)->SetType(MazeBlock::BlockType::VISITED);
			_path.push_back(pos);
		}

		//오른쪽 손 짚어도 못가고, 앞으로도 못가는 상황 반시계로 회전
		else
		{
			curDir = static_cast<Dir>((curDir + 1 + Dir::DIR_COUNT) % Dir::DIR_COUNT);
		}
	}
	

	stack<Vector2> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
			s.push(_path[i]);
	}

	s.push(_endPos);

	_path.clear();

	while (true)
	{
		if (s.empty())
			break;
		_path.push_back(s.top());
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());

	return;

}

void Player::BFS()
{
	Vector2 poolCount = _maze.lock()->PoolCount();
	int poolCountX = (int)poolCount.x;
	int poolCountY = (int)poolCount.y;
	_discovered = vector<vector<bool>>(poolCountY, vector<bool>(poolCountX, false));
	_parent = vector<vector<Vector2>>(poolCountY, vector<Vector2>(poolCountX, Vector2(-1, -1)));

	queue<Vector2> q;
	q.push(_startPos);
	_discovered[_startPos.y][_startPos.x] = true;
	_parent[_startPos.y][_startPos.x] = _startPos;
	_visited.push_back(_startPos);

	Vector2 frontPos[8] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0}, // RIGHT

		Vector2 {1, 1},
		Vector2 {1, -1},
		Vector2 {-1, 1},
		Vector2 {-1, -1}
	};

	while (true)
	{
		Vector2 here = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontPos[i];
			if (Cango(there) == false)
				continue;

			if (_discovered[there.y][there.x] == true)
				continue;

			q.push(there);
			_discovered[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
			_visited.push_back(there);

			if (there == _endPos)
				break;
		}

		if (_visited.back() == _endPos)
		{
			Vector2 check = _endPos;

			while (true)
			{
				_path.push_back(check);

				if (check == _parent[check.y][check.x])
					break;

				check = _parent[check.y][check.x];
			}

			std::reverse(_path.begin(), _path.end());
			break;
		}
	}
	return;
}

void Player::DFS()
{
	Vector2 poolCount = _maze.lock()->PoolCount();
	int poolCountX = (int)poolCount.x;
	int poolCountY = (int)poolCount.y;
	_discovered = vector<vector<bool>>(poolCountY, vector<bool>(poolCountX, false));

	_discovered[_startPos.y][_startPos.x] = true;
	_visited.push_back(_startPos);

	DFS(_startPos);

	std::reverse(_path.begin(), _path.end());
}

void Player::DFS(Vector2 here)
{
	Vector2 frontPos[4] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0}, // RIGHT
	};

	_discovered[here.y][here.x] = true;
	_visited.push_back(here);

	for (int i = 0; i < 4; i++)
	{
		Vector2 there = here + frontPos[i];
		if (here == there)
			continue;
		if (Cango(there) == false)
			continue;
		if (_discovered[there.y][there.x] == true)
			continue;
		if (_visited.back() == _endPos)
			break;

		DFS(there);
	}

	if (_visited.back() == _endPos)
	{
		_path.push_back(here);
	}
}

void Player::Dijkstra()
{
	struct Vertex
	{
		Vector2 vertexVector;
		int cost;

		bool operator<(const Vertex& other) const
		{
			return cost < other.cost;
		}

		bool operator>(const Vertex& other) const
		{
			return cost > other.cost;
		}
	};

	Vector2 frontPos[8] =
	{
		Vector2 {0, -1}, // UP
		Vector2 {-1, 0}, // LEFT
		Vector2 {0, 1}, // DOWN
		Vector2 {1, 0}, // RIGHT

		Vector2 {1, 1},
		Vector2 {1, -1},
		Vector2 {-1, 1},
		Vector2 {-1, -1}
	};

	Vector2 poolCount = _maze.lock()->PoolCount();
	int poolCountX = (int)poolCount.x;
	int poolCountY = (int)poolCount.y;

	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
	vector<vector<int>> _best = vector<vector<int>>(poolCountY, vector<int>(poolCountX, INT_MAX));
	_parent = vector<vector<Vector2>>(poolCountY, vector<Vector2>(poolCountX, Vector2(-1, -1)));

	Vertex start;
	start.vertexVector = _startPos;
	start.cost = 0;

	pq.push(start);
	_best[start.vertexVector.y][start.vertexVector.x] = start.cost;
	_parent[start.vertexVector.y][start.vertexVector.x] = start.vertexVector;

	while (true)
	{
		if (pq.empty())
			break;

		int cost = pq.top().cost;
		Vector2 here = pq.top().vertexVector;
		_visited.push_back(here);

		if (here == _endPos)
			break;

		pq.pop();

		if (_best[here.y][here.x] < cost)
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector2 there = here + frontPos[i];

			if (Cango(there) == false)
				continue;

			int nextCost;
			if (i < 4)
				nextCost = _best[here.y][here.x] + 10;
			else
				nextCost = _best[here.y][here.x] + 14;

			if (nextCost >= _best[there.y][there.x])
				continue;

			Vertex v;
			v.vertexVector = there;
			v.cost = nextCost;
			pq.push(v);
			_best[there.y][there.x] = nextCost;
			_parent[there.y][there.x] = here;
		}
	}

	Vector2 check = pq.top().vertexVector;
	while (true)
	{
		_path.push_back(check);

		if (_parent[check.y][check.x] == check)
			break;

		check = _parent[check.y][check.x];
	}

	std::reverse(_path.begin(), _path.end());
}
