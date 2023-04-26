#pragma once
class Stage
{
public:
	Stage();
	~Stage();

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<Brick>>>& GetBricks() { return _bricks; }

private:
	UINT _poolCountX = 12;
	UINT _poolCountY = 10;

	Vector2 _offSet = Vector2((int)CENTER.x - BRICKSIZEX * 6 + (int)(BRICKSIZEX * 0.5f), BRICKSIZEY * 3);

	vector<vector<shared_ptr<Brick>>> _bricks;

};

