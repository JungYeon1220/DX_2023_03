#include "framework.h"
#include "DunPlayer.h"

DunPlayer::DunPlayer()
{
	_player = make_shared<Quad>(L"Resource/Texture/Player.png");
	_bowTrans = make_shared<Transform>();
	_bow = make_shared<Quad>(L"Resource/Texture/Item_11x5.jpg");
	_bulletTrans = make_shared<Transform>();

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		_bullets.push_back(bullet);
	}

	_player->GetTransform()->SetPosition(Vector2(80.0f, 80.0f));
	_bowTrans->SetParent(_player->GetTransform());

	_bow->GetTransform()->SetAngle(-3.14159f * 0.75f);
	_bow->GetTransform()->SetPosition(Vector2(80.0f, 0.0f));
	_bow->GetTransform()->SetParent(_bowTrans);

	_bulletTrans->SetParent(_bowTrans);
	_bulletTrans->SetPosition(Vector2(120.0f, 0.0f));
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Update()
{
	_bowTrans->SetAngle((MOUSE_POS - _bowTrans->GetWorldPos()).Angle());

	Fire();

	_player->Update();
	_bowTrans->Update();
	_bow->Update();
	_bulletTrans->Update();

	for (auto bullet : _bullets)
		bullet->Update();
}

void DunPlayer::Render()
{
	for (auto bullet : _bullets)
		bullet->Render();
	_bow->Render();
	_player->Render();
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

		bullet->SetPos(_bulletTrans->GetWorldPos());
		bullet->SetDir((MOUSE_POS - _bowTrans->GetWorldPos() + Vector2(0.0f, -36.0f)));
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