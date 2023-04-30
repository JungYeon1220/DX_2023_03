#include "framework.h"
#include "Collider.h"

Collider::Collider(Vector2 center)
	:_center(center)
{
	_type = Type::NONE;
	CreatePens();
	CreateBrushes();
}

Collider::~Collider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void Collider::Update()
{
}

void Collider::Render(HDC hdc)
{
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
	switch (col->_type)
	{
	case Collider::Type::NONE:
		return false;
	case Collider::Type::CIRCLE:
		return IsCollision(dynamic_pointer_cast<CircleCollider>(col));
	case Collider::Type::RECT:
		return IsCollision(dynamic_pointer_cast<RectCollider>(col));
	default:
		return false;
	}
}

void Collider::CreatePens()
{
	_curPenIndex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));   // 1
}

void Collider::CreateBrushes()
{
	_curBrushIndex = 0;

	_brushes.push_back(CreateSolidBrush(WHITE));
	_brushes.push_back(CreateSolidBrush(GREY));
	_brushes.push_back(CreateSolidBrush(DARK_GREY));
	_brushes.push_back(CreateSolidBrush(RED));
	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(BLUE));
}

bool Collider::IsCollision(const Vector2& pos)
{
	return false;
}
