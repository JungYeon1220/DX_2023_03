#pragma once
class TileMapScene : public Scene
{
public:
	TileMapScene();
	~TileMapScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	vector<vector<shared_ptr<class Tile>>> _tileMap;

	UINT _poolCountX = 10;
	UINT _poolCountY = 8;
	Vector2 _offSet = Vector2(0.0f, 0.0f);
};

