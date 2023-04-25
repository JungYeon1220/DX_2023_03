#include "framework.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();
	_brick = make_shared<Brick>();
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	if (_ball->_isStart == false)
	{
		_ball->SetPosition(Vector2(_bar->GetPosition().x + 15, _bar->GetPosition().y - _bar->GetSize().y * 0.5f - _ball->GetRadius() + 1));
	}

	_ball->Collision(_bar);

	_bar->Update();
	_ball->Update();
	_brick->Update();
}

void Arkanoid::Render(HDC hdc)
{
	_bar->Render(hdc);
	_brick->Render(hdc);
	_ball->Render(hdc);
}
