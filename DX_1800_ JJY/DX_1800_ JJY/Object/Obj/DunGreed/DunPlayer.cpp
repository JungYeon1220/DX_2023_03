#include "framework.h"
#include "DunPlayer.h"

DunPlayer::DunPlayer()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Player.png");
	_trans = make_shared<Transform>();
	_bow = make_shared<Quad>(L"Resource/Texture/Item_11x5.jpg");
	_muzzle = make_shared<Transform>();
	_bullet = make_shared<DunBullet>();
	for (int i = 0; i < 10; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		_bullets.push_back(bullet);
	}

	_quad->GetTransform()->SetPosition(Vector2(80.0f, 80.0f));
	_trans->SetParent(_quad->GetTransform());

	_bow->GetTransform()->SetAngle(-3.14159f * 0.75f);
	_bow->GetTransform()->SetPosition(Vector2(80.0f, 0.0f));
	_bow->GetTransform()->SetParent(_trans);

	_muzzle->SetParent(_trans);
	_muzzle->SetPosition(Vector2(120.0f, 0.0f));
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Update()
{
	_trans->SetAngle((mousePos - _trans->GetWorldPos() + Vector2(0.0f, -36.0f)).Angle());

	Fire();

	_quad->Update();
	_trans->Update();
	_bow->Update();
	_muzzle->Update();
	_bullet->Update();
	for (auto bullet : _bullets)
		bullet->Update();
}

void DunPlayer::Render()
{
	_bullet->Render();
	for (auto bullet : _bullets)
		bullet->Render();
	_bow->Render();
	_quad->Render();
}

void DunPlayer::Fire()
{
	if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000))
	{
		_mousePress = true;
		_mouseUp = false;
	}
	else
	{
		_mouseUp = true;
	}
	if (_mousePress == true && _mouseUp == true)
	{
		shared_ptr<DunBullet> bullet = SetBullet();

		if (bullet == nullptr)
			return;

		bullet->SetPos(_muzzle->GetWorldPos());
		bullet->SetDir((mousePos - _trans->GetWorldPos() + Vector2(0.0f, -36.0f)));
		bullet->SetActive(true);

		_mousePress = false;
		_mouseUp = false;
	}
}

shared_ptr<DunBullet> DunPlayer::SetBullet()
{
	for (auto bullet : _bullets)
	{
		if (bullet->IsActive() == true)
			continue;
		else
			return bullet;
	}
	return nullptr;
}
