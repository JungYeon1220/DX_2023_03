#include "framework.h"
#include "Brick.h"

Brick::Brick()
{
	_rect = make_shared<RectCollider>(CENTER, Vector2(60, 20));
}

Brick::~Brick()
{
}

void Brick::Update()
{
	if(_isActive == true)
	{
		dynamic_pointer_cast<RectCollider>(_rect)->SetSize(_size);
		_rect->SetCenter(_pos);
		_rect->Update();
	}
}

void Brick::Render(HDC hdc)
{
	if (_isActive == true)
	{
		_rect->Render(hdc);
	}
}
