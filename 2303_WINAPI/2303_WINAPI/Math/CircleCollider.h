#pragma once
class CircleCollider
{
public:
	CircleCollider() {}
	CircleCollider(Vector2 center, float radius)
		:_center(center), _radius(radius) {}
	~CircleCollider() {}

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector2 center) { _center = center; }
	const Vector2& GetCenter() { return _center; }

	void SetRadius(float radius) { _radius = radius; }
	const float& GetRadius() { return _radius; }

private:
	// ¸â¹öº¯¼ö
	float _radius = 0.0f;
	Vector2 _center = { 0.0f, 0.0f };
};

