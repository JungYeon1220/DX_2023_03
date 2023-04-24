#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_circle = make_shared<CircleCollider>(Vector2(-100, -100), 10);
	_pos = _circle->GetCenter();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	_pos += _direction * _speed;
	_circle->SetCenter(_pos);

	_circle->Update();

}

void Bullet::Render(HDC hdc)
{
	_circle->Render(hdc);
}
