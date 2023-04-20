#pragma once
class CircleCollider
{
public:
	CircleCollider() { CreatePens(); }
	CircleCollider(Vector2 center, float radius)
		:_center(center), _radius(radius) {
		CreatePens();
	}
	~CircleCollider()
	{
		for (auto pen : _pens)
		{
			DeleteObject(pen);
		}
	}

	void Update();
	void Render(HDC hdc);

	void SetCenter(Vector2 center) { _center = center; }
	const Vector2& GetCenter() { return _center; }

	void SetRadius(float radius) { _radius = radius; }
	const float& GetRadius() { return _radius; }

	bool IsCollision(Vector2 pos);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr< class RectCollider> other);

	void SetGreen() { _curPenIdex = 0; }
	void SetRed() { _curPenIdex = 1; }

private:
	void CreatePens();

	int _curPenIdex;
	vector<HPEN> _pens;

	float _radius = 0.0f;
	Vector2 _center = { 0.0f, 0.0f };
};

