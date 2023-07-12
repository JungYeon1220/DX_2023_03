#pragma once
class Tile
{
public:
	Tile();
	~Tile();

	void Update();
	void Render();
private:
	shared_ptr<Sprite_Frame> _sprite;
	shared_ptr<Transform> _transform;
};

