#include "framework.h"
#include "RectCollider.h"

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _center.x - _width / 2;
	float right = _center.x + _width / 2;
	float bottom = _center.y + _height / 2;
	float top = _center.y - _height / 2;

	Rectangle(hdc, left, top, right, bottom);
}
