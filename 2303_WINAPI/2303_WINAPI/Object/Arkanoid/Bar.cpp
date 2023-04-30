#include "framework.h"
#include "Bar.h"

Bar::Bar()
{
	_rect = make_shared<RectCollider>(Vector2(CENTER.x, 650.0f), Vector2(100, 20));
}

Bar::~Bar()
{
}

void Bar::Update()
{
	MoveByInput();
	_rect->SetCenter(_pos);
	dynamic_pointer_cast<RectCollider>(_rect)->SetSize(_size);
	_rect->Update();
}

void Bar::Render(HDC hdc)
{
	SelectObject(hdc, CreateSolidBrush(WHITE));

	_rect->Render(hdc);
}

void Bar::MoveByInput()
{
	if (GetAsyncKeyState('A') && dynamic_pointer_cast<RectCollider>(_rect)->Left() > CENTER.x - BRICKSIZEX * 6 + 5)
	{
		_pos.x -= _speed;
	}
	if (GetAsyncKeyState('D') && dynamic_pointer_cast<RectCollider>(_rect)->Right() < CENTER.x + BRICKSIZEX * 6 - 2)
	{
		_pos.x += _speed;
	}
}
