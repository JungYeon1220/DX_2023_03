#include "framework.h"
#include "DunGreed.h"

#include "../../Object/Obj/DunGreed/DunPlayer.h"
#include "../../Object/Obj/DunGreed/DunBullet.h"
#include "../../Object/Obj/DunGreed/DunMonster.h"

DunGreed::DunGreed()
{
	_player = make_shared<DunPlayer>();
	_player->SetPosition(Vector2(0,0));

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<DunMonster> monster = make_shared<DunMonster>();

		float xPos = rand() % WIN_WIDTH - CENTER.x;
		float yPos = rand() % WIN_HEIGHT - CENTER.y;

		monster->GetTransform()->SetPosition(Vector2(xPos, yPos));
		_monsters.push_back(monster);
	}
<<<<<<< HEAD

	_button = make_shared<Button>(L"Resource/Texture/Button.png", Vector2(500.0f, 30.0f));
	_button->SetPS(L"Shader/HpBarPS.hlsl");
	_button->SetPosition(Vector2(0.0f, -300.0f));
	_hpBuffer = make_shared<HpBuffer>();
	_hpBuffer->_data.maxHp = 10;
=======
>>>>>>> parent of 3c50655 (Button)
}

DunGreed::~DunGreed()
{
}

void DunGreed::Update()
{
	_player->Update();

	for (auto monster : _monsters)
	{
		monster->Update();
		monster->SetDir(_player->GetTransform()->GetWorldPos());

		if (_player->GetHp() <= 0)
			continue;

		if (_player->GetCollider()->Block(monster->GetCollider()))
			_player->TakeDamage(1);

		for (auto bullet : _player->GetBullets())
		{
			bullet->Attack(monster);
		}

		for (auto bible : _player->GetBibles())
		{
			if (bible->IsCollision(monster->GetCollider()) && monster->IsDamaged() == false)
			{
				Vector2 temp = monster->GetTransform()->GetWorldPos() - _player->GetTransform()->GetWorldPos();
				temp.Normalize();
				monster->GetTransform()->AddVector2(temp * 20.0f);
				monster->TakeDamage(1);
			}
		}
	}

	_hpBuffer->_data.hp = _player->GetHp();
	_hpBuffer->Update_Resource();
	_button->Update();
}

void DunGreed::Render()
{
	_player->Render();
	for (auto monster : _monsters)
	{
		monster->Render();
	}
}

void DunGreed::PostRender()
{
	for (int i = 0; i < _monsters.size(); i++)
	{
		ImGui::Text("Monster%d HP : %d", i + 1, _monsters[i]->GetHp());
	}

	_hpBuffer->SetPS_Buffer(0);
	_button->PostRender();
}
