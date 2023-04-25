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
	if (_isActive == false)
		return;

	_pos += _direction * _speed;
	//_direction.y += GRAVITY;

	_circle->SetCenter(_pos);
	_circle->Update();

	//if (_pos.x > WIN_WIDTH || _pos.x < 0)
	//	_isActive = false;
	//if (_pos.y > WIN_HEIGHT || _pos.y < 0)
	//	_isActive = false;
}

void Bullet::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_circle->Render(hdc);
}

bool Bullet::AttackCannon(shared_ptr<Cannon> cannon)
{
	if (_circle->IsCollision(cannon->GetBody()))
	{
		cannon->GetHp() -= _damage;
		_isActive = false;
		return true;
	}
	return false;
}
