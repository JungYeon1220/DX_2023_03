#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(CENTER, 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if((GetAsyncKeyState(VK_SPACE)))
		_isStart = true;

	if (_isStart == true)
	{
		_pos += _direction * _speed;
	}

	if (_pos.x > WIN_WIDTH - GetRadius() || _pos.x < 0 + GetRadius())
		_direction.x = -_direction.x;
	if (_pos.y < 0 + GetRadius())
		_direction.y = -_direction.y;
	if (_pos.y > WIN_HEIGHT + GetRadius())
	{
		_isStart = false;
	}

	_circle->SetCenter(_pos);
	_circle->Update();
}

void Ball::Render(HDC hdc)
{
	_circle->Render(hdc);
}

void Ball::Collision(shared_ptr<Bar> bar)
{
	if (_circle->GetCenter().y < bar->GetTop() && _circle->IsCollision(bar->GetRect()))
		SetDirection(_circle->GetCenter() - bar->GetPosition());
}
