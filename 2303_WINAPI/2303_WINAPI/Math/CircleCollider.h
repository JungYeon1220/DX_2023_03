#pragma once
class CircleCollider : public enable_shared_from_this<CircleCollider>, public Collider
{
public:
	CircleCollider() : Collider(Vector2(0,0)) { _type = Collider::Type::CIRCLE; }
	CircleCollider(Vector2 center, float radius)
		:Collider(center), _radius(radius) { _type = Collider::Type::CIRCLE; }
	virtual ~CircleCollider() {}

	float Left() const { return _center.x - _radius; }
	float Right() const { return _center.x + _radius; }
	float Bottom() const { return _center.y + _radius; }
	float Top() const { return _center.y - _radius; }

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetRadius(float radius) { _radius = radius; }
	const float& GetRadius() { return _radius; }

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr< class RectCollider> other) override;

private:

	float _radius = 0.0f;

};

