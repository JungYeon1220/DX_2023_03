#include "framework.h"
#include "Line.h"

Line::~Line()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPenIdex]);

	MoveToEx(hdc, _startPos.x, _startPos.y, nullptr);
	LineTo(hdc, _endPos.x, _endPos.y);
}

bool Line::IsCollision(shared_ptr<Line> other)
{
	Vector2 lineVector1 = _endPos - _startPos;
	Vector2 startVector1 = other->_startPos - _startPos;
	Vector2 endVector1 = other->_endPos - _startPos;

	Vector2 lineVector2 = other->_endPos - other->_startPos;
	Vector2 startVector2 = _startPos - other->_startPos;
	Vector2 endVector2 = _endPos - other->_startPos;

	float result1 = lineVector1.Cross(startVector1) * lineVector1.Cross(endVector1);
	float result2 = lineVector2.Cross(startVector2) * lineVector2.Cross(endVector2);

	if (result1 <= 0 && result2 <= 0)
		return true;
	else
		return false;
}

Vector2 Line::GetIntersectPoint(shared_ptr<Line> other)
{
	if (IsCollision(other))
	{
		Vector2 unitLine1Vector = (_endPos - _startPos).NormalVector2();
		Vector2 unitLine2Vector = (other->_endPos - other->_startPos).NormalVector2();

		Vector2 unitPerpToLine2;
		unitPerpToLine2.x = -unitLine2Vector.y;
		unitPerpToLine2.y = unitLine2Vector.x;

		float angleFromLine1ToPerpLine2 = unitPerpToLine2.Angle() - unitLine1Vector.Angle();

		float length = unitPerpToLine2.Dot(other->_endPos - _startPos) / std::cosf(angleFromLine1ToPerpLine2);

		Vector2 intersectPoint = _startPos + (unitLine1Vector * length);

		return intersectPoint;
	}
	else
		return Vector2();
}

void Line::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));   // 1
}
