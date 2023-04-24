#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector2(CENTER), 50);
	Vector2 barrelEnd = _body->GetCenter() + Vector2(_barrelLength, 0.0f);
	_barrel = make_shared<Line>(_body->GetCenter(), barrelEnd);
	_direction = (_barrel->_endPos - _barrel->_startPos).NormalVector2();

	_bullet = make_shared<Bullet>();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	MoveByInput();

	_body->SetCenter(_pos);
	_barrel->_startPos = _pos;
	_barrel->_endPos = _pos + _direction * _barrelLength;

	_body->Update();
	_barrel->Update();

	_bullet->Update();
}

void Cannon::Render(HDC hdc)
{
	_body->Render(hdc);
	_barrel->Render(hdc);

	_bullet->Render(hdc);
}

void Cannon::MoveByInput()
{
	if (GetAsyncKeyState('A'))
	{
		_pos.x += _speed;
	}
	if (GetAsyncKeyState('D'))
	{
		_pos.x -= _speed;
	}
	if (GetAsyncKeyState('W'))
	{
		_angle += 0.1f;
	}
	if (GetAsyncKeyState('S'))
	{
		_angle -= 0.1f;
	}

	_direction.x = cos(_angle);
	_direction.y = sin(_angle);
}

void Cannon::Fire()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		_bullet->SetDirection(_direction);
		Vector2 muzzle = _barrel->_endPos;
		_bullet->SetPos(muzzle);
	}
}
