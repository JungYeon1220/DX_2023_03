#pragma once
class Tile
{
public:
	enum Type
	{
		EMPTY,
		NORMAL,
	};
	Tile();
	~Tile();

	void TileSelect(Type value);
	void SetPosition(Vector2 pos) { _pos = pos; }

	void Update();
	void Render();

	shared_ptr<RectCollider> GetCollider() { return _col; }
	float GetSize() { return _sprite->GetClipsize().x; }
private:
	shared_ptr<RectCollider> _col;
	shared_ptr<Sprite_Frame> _sprite;
	shared_ptr<Transform> _transform;

	Vector2 _pos = CENTER;
	Vector2 _selected = Vector2(0, 0);
	Type _type = EMPTY;
};

