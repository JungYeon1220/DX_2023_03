#include "framework.h"
#include "RectCollider.h"

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	// SelectObject(hdc, _pens[_curPenIdex]);

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

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{

	if (other->GetCenter().x < Right() && other->GetCenter().x > Left())
	{
		if (other->Bottom() > Top() && other->Top() < Bottom())
		{
			return true;
		}
	}

	if (other->GetCenter().y < Bottom() && other->GetCenter().y > Top())
	{
		if (other->Left() < Right() && other->Right() > Left())
		{
			return true;
		}
	}

	if (other->IsCollision(Vector2(Left(), Top()))
		|| other->IsCollision(Vector2(Right(), Top()))
		|| other->IsCollision(Vector2(Left(), Bottom()))
		|| other->IsCollision(Vector2(Right(), Bottom())))
	{
		return true;
	}

	return false;
}
