#include "framework.h"
#include "DunGreed.h"

DunGreed::DunGreed()
{
	_player = make_shared<DunPlayer>();
	_monster = make_shared<DunMonster>();
	_player->SetPosition(CENTER + Vector2(-200.0f, 0.0f));
	_monster->GetTransform()->SetPosition(CENTER + Vector2(200.0f, 0.0f));
}

DunGreed::~DunGreed()
{
}

void DunGreed::Update()
{
	_player->Update();
	_monster->Update();

	for (auto bullet : _player->GetBullets())
	{
		bullet->Attack(_monster);
	}
}

void DunGreed::Render()
{
	_player->Render();
	_monster->Render();
	ImGui::Text("%d", _monster->GetHp());
}
