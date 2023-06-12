#include "framework.h"
#include "DunBullet.h"

DunBullet::DunBullet()
{
	_quad = make_shared<Quad>(Vector2(30,30),L"Resource/Texture/Bullet.png");
	_collider = make_shared<CircleCollider>(15.0f);

	_quad->GetTransform()->SetParent(_collider->GetTransform());
}

DunBullet::~DunBullet()
{
}

void DunBullet::Update()
{
	if (_isActive == false)
		return;

	if (_pos.x > WIN_WIDTH || _pos.x < 0.0f)
		_isActive = false;
	if (_pos.y > WIN_HEIGHT || _pos.y < 0.0f)
		_isActive = false;

	_pos += _dir * _speed * DELTA_TIME;
	_collider->GetTransform()->SetPosition(_pos);
	_collider->GetTransform()->SetAngle(_dir.Angle());
	_quad->Update();
	_collider->Update();
}

void DunBullet::Render()
{
	if (_isActive == false)
		return;

	_quad->Render();
	_collider->Render();
}

void DunBullet::Attack(shared_ptr<DunMonster> victim)
{
	if (_isActive == false)
		return;
	if (_collider->IsCollision(victim->GetCollider()) == false || victim->IsDead() == true)
		return;

	victim->TakeDamage(_damage);
	_isActive = false;
}
