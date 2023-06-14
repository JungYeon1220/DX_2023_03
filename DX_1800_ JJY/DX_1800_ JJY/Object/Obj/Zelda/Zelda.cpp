#include "framework.h"
#include "Zelda.h"

Zelda::Zelda()
{
	_sprite = make_shared<Sprite>(L"Resource/Texture/zelda.png", Vector2(10, 8), Vector2(200, 200));
	_transform = make_shared<Transform>();
	_transform->SetPosition(CENTER);

	_sprite->SetCurFrame(Vector2(0, 0));
}

Zelda::~Zelda()
{
}

void Zelda::Update()
{
	if (KEY_DOWN('S'))
	{
		_sprite->SetCurFrame(Vector2(0, 0));
	}
	if (KEY_DOWN('W'))
	{
		_sprite->SetCurFrame(Vector2(0, 2));
	}
	if (KEY_DOWN('A'))
	{
		_sprite->SetCurFrame(Vector2(0, 1));
	}
	if (KEY_DOWN('D'))
	{
		_sprite->SetCurFrame(Vector2(0, 3));
	}

	_transform->Update();
	_sprite->Update();
}

void Zelda::Render()
{
	_transform->SetWorldBuffer(0);
	_sprite->Render();
}
