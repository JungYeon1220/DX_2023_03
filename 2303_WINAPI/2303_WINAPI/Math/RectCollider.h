#pragma once
class RectCollider
{
public:
	RectCollider() {}
	RectCollider(Vector2 center, float height, float width)
		: _center(center), _height(height), _width(width) {}
	~RectCollider() {}

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector2 center) { _center = center; }
	const Vector2& GetCenter() { return _center; }

	void SetHeight(float height) { _height = height; }
	const float& GetHeight() { return _height; }

	void SetWidth(float width) { _width = width; }
	const float& GetWidth() { return _width; }

private:
	Vector2 _center = { 0.0f, 0.0f };
	float _height = 0.0f;
	float _width = 0.0f;
};

