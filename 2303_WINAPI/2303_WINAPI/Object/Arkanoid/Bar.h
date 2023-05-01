#pragma once
class Bar
{
public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);

	Vector2& GetPosition() { return _pos; }
	Vector2& GetSize() { return _size; }
	float GetTop() { return _pos.y - _size.y * 0.5f; }
	shared_ptr<Collider>& GetRect() { return _rect; }

	void MoveByInput();

private:
	shared_ptr<Collider> _rect;

	Vector2 _pos = Vector2(CENTER.x, 650.0f);
	Vector2 _size = Vector2(100, 15);
	float _speed = 4.8f;

};

