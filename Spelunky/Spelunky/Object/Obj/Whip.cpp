#include "framework.h"
#include "Whip.h"

Whip::Whip()
{
	_transform = make_shared<Transform>();
	_sprite = make_shared<Sprite_Frame>(L"Resource/Texture/char_yellow.png", Vector2(16, 16));

	shared_ptr<SRV> srv = ADD_SRV(L"Resource/Texture/char_yellow.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = Vector2(16, 16);
	Vector2 size;
	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;

	vector<Action::Clip> clips;
	for (int i = 10; i < 16; i++)
	{
		Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 12.0f / maxFrame.y);
		Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
		clips.push_back(clip);
	}

	_action = make_shared<Action>(clips, "WHIP", Action::END);
	_action->SetEndEvent(std::bind(&Whip::End, this));
}

Whip::~Whip()
{
}

void Whip::Attack()
{
	_isActive = true;
	_action->Reset();
	_action->Play();
}

void Whip::End()
{
	_isActive = false;
}

void Whip::Update()
{
	if (KEY_DOWN('X'))
		Attack();

	if (_isActive == false)
		return;

	if (_action->GetCurIndex() <= 2)
		_transform->SetPosition(Vector2(-55.0f, -10.0f));
	else
		_transform->SetPosition(Vector2(55.0f, -10.0f));

	_transform->Update();
	_action->Update();
	_sprite->SetCurClip(_action->GetCurClip());
	_sprite->Update();
}

void Whip::Render()
{
	if (_isActive == false)
		return;

	_transform->SetWorldBuffer(0);
	_sprite->Render();
}

void Whip::SetLeft()
{
	_sprite->SetLeft();
}

void Whip::SetRight()
{
	_sprite->SetRight();
}
