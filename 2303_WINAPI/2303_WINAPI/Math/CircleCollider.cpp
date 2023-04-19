#include "framework.h"
#include "CircleCollider.h"

void CircleCollider::Update()
{

}

void CircleCollider::Render(HDC hdc)
{
	float left = _center.x - _radius;
	float right = _center.y - _radius;
	float bottom = _center.x + _radius;
	float top = _center.y + _radius;
	Ellipse(hdc, left, right, bottom, top);
}
