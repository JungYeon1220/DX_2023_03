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
	_rect->Update();
}

void Brick::Render(HDC hdc)
{
	_rect->Render(hdc);
}
