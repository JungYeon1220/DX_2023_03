#include "framework.h"
#include "CupHeadScene.h"
#include "../../Object/Obj/CupHead/CupHead.h"
#include "../../Object/Obj/CupHead/CupBG.h"
#include "../../Object/Obj/CupHead/CupMonster.h"
#include "../../Object/Obj/CupHead/CupBullet.h"

CupHeadScene::CupHeadScene()
{
	_player = make_shared<CupHead>();
	_bg = make_shared<CupBG>();
	_bg->SetPosition(Vector2(0.0f, -300.0f));
	_monster = make_shared<CupMonster>();

	CAMERA->SetTarget(_player->GetCollider()->GetTransform());
	CAMERA->SetLeftBottom(_bg->LeftBottom());
	CAMERA->SetRightTop(_bg->RightTop());

	EFFECT->AddEffect("Hit", L"Resource/Texture/hit_4x2.png", Vector2(4, 2), Vector2(100, 100));
	
}

CupHeadScene::~CupHeadScene()
{
}

void CupHeadScene::Update()
{
	_player->Update();
	_monster->Update();
	_bg->Update();

	if (_bg->GetCollider()->Block(_player->GetCollider()))
		_player->Grounded();
	else
		_player->SetIsFalling(true);

	if (_player->GetBullet()->GetCollider()->IsCollision(_monster->GetCollider()))
	{
		_player->GetBullet()->_isActive = false;
		EFFECT->Play("Hit", _player->GetBullet()->GetCollider()->GetWorldPos());
	}

}

void CupHeadScene::Render()
{
	_bg->Render();
	_monster->Render();
	_player->Render();
}

void CupHeadScene::PostRender()
{
	_player->PostRender();
}
