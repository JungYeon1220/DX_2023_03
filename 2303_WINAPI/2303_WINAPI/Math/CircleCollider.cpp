#include "framework.h"
#include "CircleCollider.h"

void CircleCollider::Update()
{

}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);

	float left = _center.x - _radius;
	float right = _center.y - _radius;
	float bottom = _center.x + _radius;
	float top = _center.y + _radius;
	Ellipse(hdc, left, right, bottom, top);
}

bool CircleCollider::IsCollision(const Vector2& pos)
{
	float distance = _center.Distance(pos);
	return distance < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return other->IsCollision(shared_from_this());
}

