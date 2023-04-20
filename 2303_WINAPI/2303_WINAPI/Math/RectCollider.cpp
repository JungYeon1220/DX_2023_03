#include "framework.h"
#include "RectCollider.h"

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);

	float left = _center.x - _size.x * 0.5f;
	float right = _center.x + _size.x * 0.5f;
	float bottom = _center.y + _size.y * 0.5f;
	float top = _center.y - _size.y * 0.5f;

	Rectangle(hdc, left, top, right, bottom);
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	if (Top() > other->Bottom() || Bottom() < other->Top()
	|| Right() < other->Left() || Left() > other->Right())
	{
		return false;
	}

	return true;
}

bool RectCollider::IsCollision(const Vector2& pos)
{
	if (pos.x < Right() && pos.x >Left())
	{
		if (pos.y < Bottom() && pos.y > Top())
			return true;
	}

	return false;
}

void RectCollider::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));   // 1
}
