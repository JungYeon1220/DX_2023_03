#include "framework.h"
#include "DunPlayer.h"
#include "DunBullet.h"

DunPlayer::DunPlayer()
{
	_col = make_shared<CircleCollider>(50.0f);
	_player = make_shared<Quad>(L"Resource/Texture/Player.png");
	_quadTrans = make_shared<Transform>();

	_bowSlot = make_shared<Transform>();
	_bowTrans = make_shared<Transform>();
	_bow = make_shared<Quad>(L"Resource/Texture/Item_11x5.jpg");

	_bulletTrans = make_shared<Transform>();

	_bibleSlot = make_shared<Transform>();

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<DunBullet> bullet = make_shared<DunBullet>();
		_bullets.push_back(bullet);
	}

	_quadTrans->SetParent(_col->GetTransform());

	_bowSlot->SetParent(_quadTrans);

	_bowTrans->SetAngle(-PI * 0.75f);
	_bowTrans->SetPosition(Vector2(80.0f, 0.0f));
	_bowTrans->SetParent(_bowSlot);

	_bulletTrans->SetParent(_bowTrans);
	_bulletTrans->SetPosition(Vector2(-20.0f, 20.0f));

	_bibleSlot->SetPosition(_col->GetWorldPos());

	for (int i = 0; i < 3; i++)
	{
		shared_ptr<CircleCollider> bible = make_shared<CircleCollider>(15.0f);
		float xPos = cos(2 * PI / 3 * i) * 120.0f;
		float yPos = sin(2 * PI / 3 * i) * 120.0f;
		bible->GetTransform()->SetPosition(Vector2(xPos, yPos));
		bible->GetTransform()->SetParent(_bibleSlot);
		_bibles.push_back(bible);

		shared_ptr<Quad> quad = make_shared<Quad>(Vector2(35.0f, 35.0f), L"Resource/Texture/sun.png");
		shared_ptr<Transform> trans = make_shared<Transform>();
		trans->SetParent(bible->GetTransform());
		_bibleQuads.push_back(quad);
		_bibleTrans.push_back(trans);
	}
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Update()
{
<<<<<<< HEAD
	if (_hp <= 0)
		return;

	if (_isDamaged == true)
	{
		_curTime += DELTA_TIME;
	}

	if (_curTime > _damageTime)
	{
		_isDamaged = false;
		_curTime = 0.0f;
	}

	_bowSlot->SetAngle((W_MOUSE_POS - _bowSlot->GetWorldPos()).Angle());
=======
	_bowSlot->SetAngle((MOUSE_POS - _bowSlot->GetWorldPos()).Angle());
>>>>>>> parent of 3c50655 (Button)

	for (auto bullet : _bullets)
	{
		if (bullet->IsActive() == false)
			bullet->GetTransform()->SetPosition(_bulletTrans->GetWorldPos());
	}

	_bibleSlot->SetPosition(_col->GetWorldPos());
	_bibleSlot->AddAngle(3.0f * DELTA_TIME);

	Move();
	Fire();

	_col->Update();
	_player->Update();
	_quadTrans->Update();
	_bowSlot->Update();
	_bowTrans->Update();
	_bow->Update();
	_bulletTrans->Update();

	_bibleSlot->Update();

	for (auto bullet : _bullets)
		bullet->Update();

	for (auto bible : _bibles)
		bible->Update();

	for (auto bibleQuad : _bibleQuads)
		bibleQuad->Update();

	for (auto Trans : _bibleTrans)
		Trans->Update();
}

void DunPlayer::Render()
{
	if (_hp <= 0)
		return;

	for (auto bullet : _bullets)
		bullet->Render();

	for (auto bible : _bibles)
		bible->Render();

	for (int i = 0; i < 3; i++)
	{
		_bibleTrans[i]->SetWorldBuffer(0);
		_bibleQuads[i]->Render();
	}

	_bowTrans->SetWorldBuffer(0);
	_bow->Render();
	_quadTrans->SetWorldBuffer(0);
	_player->Render();
	_col->Render();
}

void DunPlayer::Move()
{
	if (KEY_PRESS('A'))
	{
		_pos.x -= _speed * DELTA_TIME;
	}
	if (KEY_PRESS('D'))
	{
		_pos.x += _speed * DELTA_TIME;
	}
	if (KEY_PRESS('W'))
	{
		_pos.y += _speed * DELTA_TIME;
	}
	if (KEY_PRESS('S'))
	{
		_pos.y -= _speed * DELTA_TIME;
	}

	_col->GetTransform()->SetPosition(_pos);
}

void DunPlayer::Fire()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		shared_ptr<DunBullet> bullet = SetBullet();

		if (bullet == nullptr)
			return;

		bullet->SetPos(_bulletTrans->GetWorldPos());
		bullet->SetDir((MOUSE_POS - _bowSlot->GetWorldPos()));
		bullet->SetActive(true);
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
