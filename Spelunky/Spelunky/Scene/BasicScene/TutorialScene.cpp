#include "framework.h"
#include "TutorialScene.h"
#include "../../Object/Obj/Player.h"
#include "../../Object/Obj/Tile.h"

TutorialScene::TutorialScene()
{
	_player = make_shared<Player>();

	_radder1 = make_shared<Tile>();
	_radder1->SetPosition(Vector2(_radder1->GetSize() - 50.0f, 150.0f) - CENTER);
	_radder1->SetType(Tile::Type::LADDER);
	_radder2 = make_shared<Tile>();
	_radder2->SetPosition(Vector2(_radder2->GetSize() - 50.0f, 250.0f) - CENTER);
	_radder2->SetType(Tile::Type::LADDER);

	for (int i = 0; i < 10; i++)
	{
		shared_ptr<Tile> tile = make_shared<Tile>();
		tile->SetPosition(Vector2((i + 0.5f) * tile->GetSize()  , 50.0f) - CENTER);
		tile->SetType(Tile::Type::NORMAL);

		_tiles.push_back(tile);
	}

	_block1 = make_shared<Tile>();
	_block2 = make_shared<Tile>();
	_block1->SetType(Tile::Type::NORMAL);
	_block2->SetType(Tile::Type::NORMAL);
	_block1->SetPosition(Vector2(_radder1->GetSize() - 50.0f, 150.0f) - CENTER + Vector2(800.0f, 0.0f));
	_block2->SetPosition(Vector2(_radder1->GetSize() - 50.0f, 150.0f) - CENTER + Vector2(800.0f, 200.0f));

	_oneWay = make_shared<Tile>();
	_oneWay->SetType(Tile::Type::ONE_WAY);
	_oneWay->SetPosition(Vector2(_radder1->GetSize() - 50.0f, 150.0f) - CENTER + Vector2(400.0f, 0.0f));

	CAMERA->SetTarget(_player->GetCollider()->GetTransform());
	CAMERA->SetLeftBottom(Vector2(-10000.0f, -10000.0f));
	CAMERA->SetRightTop(Vector2(10000.0f, 10000.0f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_radder1->Update();
	_radder2->Update();
	_block1->Update();
	_block2->Update();
	_oneWay->Update();
	_player->Update();

	bool check = false;
	for (auto tile : _tiles)
	{
		if (tile->Block(_player->GetCollider()))
		{
			check = true;
		}
		tile->Update();
	}

	if (_block1->Block(_player->GetCollider()) && _block1->GetCollider()->IsCollision(_player->GetFeetCollider()))
		check = true;

	if (_block2->Block(_player->GetCollider()))
	{
		if (_block2->GetCollider()->IsCollision(_player->GetFeetCollider()))
			check = true;
		if (_block2->GetCollider()->IsCollision(_player->GetHeadCollider()))
			_player->GetJumpPower() = 0.0f;
	}

	if (_oneWay->GetCollider()->IsCollision(_player->GetFeetCollider()) && (_player->GetJumpPower() <= 0.0f))
	{
		_oneWay->IsActive() = true;
		if (_player->GetFeetCollider()->GetWorldPos().y >= _oneWay->GetCollider()->GetWorldPos().y + 49.0f)
		{
			if (_oneWay->Block(_player->GetCollider()))
			{
				check = true;
				if (KEY_PRESS(VK_DOWN) && KEY_DOWN('Z'))
				{
					_oneWay->IsActive() = false;
				}

			}
		}
	}
	else
		_oneWay->IsActive() = false;

	if (check == false)
	{
		_player->IsFalling() = true;
	}
	else
	{
		_player->IsFalling() = false;
		_player->isClimb() = false;
	}

	if (_radder1->GetCollider()->IsCollision(_player->GetCollider()) || _radder2->GetCollider()->IsCollision(_player->GetCollider()))
	{
		if (KEY_DOWN(VK_UP) || KEY_PRESS(VK_UP))
		{
			_player->GetCollider()->GetTransform()->SetPosition(Vector2(_radder1->GetCollider()->GetWorldPos().x, _player->GetCollider()->GetWorldPos().y));
			_player->isClimb() = true;
		}
	}
	else
		_player->isClimb() = false;
}

void TutorialScene::Render()
{
	_radder1->Render();
	_radder2->Render();
	_oneWay->Render();
	_player->Render();
	for (auto tile : _tiles)
	{
		tile->Render();
	}
	_block1->Render();
	_block2->Render();
}

void TutorialScene::PostRender()
{
	_player->PostRender();
	ImGui::Text("tile x: %.0f, y: %.0f", _tiles[0]->GetCollider()->GetWorldPos().x, _tiles[0]->GetCollider()->GetWorldPos().y);
	ImGui::Text("player y: %.0f", _player->GetFeetCollider()->GetWorldPos().y);
	ImGui::Text("oneway y: %.0f", _oneWay->GetCollider()->GetWorldPos().y + 50.0f);
}
