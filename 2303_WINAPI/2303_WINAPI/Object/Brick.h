#pragma once
class Brick
{
public:
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);

	shared_ptr<RectCollider> GetRect() { return dynamic_pointer_cast<RectCollider>(_rect); }

	void SetPosition(Vector2 pos) { _pos = pos; }
	void SetSize(Vector2 size) { _size = size; }

	bool _isActive = true;
private:
	shared_ptr<Collider> _rect;

	Vector2 _pos = CENTER;
	Vector2 _size = Vector2(60, 20);
};

