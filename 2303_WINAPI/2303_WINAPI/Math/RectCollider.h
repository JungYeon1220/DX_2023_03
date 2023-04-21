#pragma once
class RectCollider : public Collider
{
public:
	RectCollider() : Collider(Vector2 (0,0)) { _type = Collider::Type::RECT; }
	RectCollider(Vector2 center, Vector2 size)
		: Collider(center), _size(size) { _type = Collider::Type::RECT; }
	virtual ~RectCollider() {}

	void Update();
	void Render(HDC hdc);

	float Left() const { return _center.x - _size.x * 0.5f; }
	float Right() const { return _center.x + _size.x * 0.5f; }
	float Bottom() const { return _center.y + _size.y * 0.5f; }
	float Top() const { return _center.y - _size.y * 0.5f; }

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;



	void SetSize(Vector2 size) { _size = size; }
	const Vector2& GetSize() { return _size; }




private:

	Vector2 _size = { 0.0f, 0.0f };
};

