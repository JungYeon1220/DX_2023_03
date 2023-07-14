#pragma once
class Tile
{
public:
	enum Type
	{
		EMPTY,
		NORMAL,
		LADDER
	};
	Tile();
	~Tile();

	void SetType(Type value);
	void SetPosition(Vector2 pos) { _pos = pos; }
	bool Block(shared_ptr<Collider> col);

	void Update();
	void Render();
	void CreateClips();

	shared_ptr<RectCollider> GetCollider() { return _col; }
	float GetSize() { return _sprite->GetClipsize().x; }
	Type GetType() { return _type; }

private:
	shared_ptr<RectCollider> _col;
	shared_ptr<Sprite_Frame> _sprite;
	shared_ptr<Transform> _transform;
	vector<Action::Clip> _clips;

	Vector2 _pos = CENTER;
	Vector2 _selected = Vector2(0, 0);
	Type _type = EMPTY;
};

