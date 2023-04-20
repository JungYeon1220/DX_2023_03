#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider() { CreatePens(); }
	CircleCollider(Vector2 center, float radius)
		:_center(center), _radius(radius) { CreatePens(); }
	~CircleCollider()
	{
		for (auto pen : _pens)
		{
			DeleteObject(pen);
		}
	}

	float Left() const { return _center.x - _radius; }
	float Right() const { return _center.x + _radius; }
	float Bottom() const { return _center.y + _radius; }
	float Top() const { return _center.y - _radius; }

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

