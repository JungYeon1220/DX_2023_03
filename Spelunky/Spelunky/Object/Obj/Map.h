#pragma once
class Map
{
public:
	Map();
	~Map();

	void Update();
	void Render();

	shared_ptr<class Tile> GetTile(int x, int y) { return _tileMap[y][x]; }

	Vector2 PoolCount() { return Vector2(_poolCountX, _poolCountY); }
private:
	void CreateTiles();

	int _poolCountX = 10;
	int _poolCountY = 12;

	vector<vector<shared_ptr<class Tile>>> _tileMap;
};

