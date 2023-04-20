#pragma once
class RectCollider
{
public:
	RectCollider() { CreatePens(); }
	RectCollider(Vector2 center, Vector2 size)
		: _center(center), _size(size) { CreatePens(); }
	~RectCollider() {}

	void Update();
	void Render(HDC hdc);

	float Left() const { return _center.x - _size.x * 0.5f; }
	float Right() const { return _center.x + _size.x * 0.5f; }
	float Bottom() const { return _center.y + _size.y * 0.5f; }
	float Top() const { return _center.y - _size.y * 0.5f; }

	bool IsCollision(shared_ptr<RectCollider> other);
	bool IsCollision(const Vector2& pos);
	bool IsCollision(shared_ptr<CircleCollider> other);

	void SetCenter(Vector2 center) { _center = center; }
	const Vector2& GetCenter() { return _center; }

	void SetSize(Vector2 size) { _size = size; }
	const Vector2& GetSize() { return _size; }


	void SetGreen() { _curPenIdex = 0; }
	void SetRed() { _curPenIdex = 1; }

private:
	void CreatePens();

	int _curPenIdex;
	vector<HPEN> _pens;

	Vector2 _center = { 0.0f, 0.0f };
	Vector2 _size = { 0.0f, 0.0f };
};

