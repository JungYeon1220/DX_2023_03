#include "framework.h"
#include "Player.h"

Player::Player()
{
	_col = make_shared<RectCollider>(Vector2(60.0f, 80.0f));
	_crouchCol = make_shared<RectCollider>(Vector2(60.0f, 40.0f));
	_transform = make_shared<Transform>();
	_sprite = make_shared<Sprite_Frame>(L"Resource/Texture/char_yellow.png", Vector2(16, 16));

	_transform->SetParent(_col->GetTransform());
	_transform->SetPosition(Vector2(0.0f, 10.0f));
	
	_crouchCol->GetTransform()->SetParent(_col->GetTransform());
	_crouchCol->GetTransform()->SetPosition(Vector2(0.0f, -20.0f));

	_col->GetTransform()->SetPosition(CENTER);
	CreateAction();

	SetAction(State::IDLE);
}

Player::~Player()
{
}

void Player::Input()
{
	if (KEY_DOWN(VK_UP))
	{
		SetAction(State::JUMP);
	}

	if (KEY_PRESS(VK_DOWN))
	{
		if (_curState != State::CRAWL)
			SetAction(State::CROUCH);

		if (KEY_PRESS(VK_LEFT))
		{
			_col->GetTransform()->AddVector2(-RIGHT_VECTOR * _speed * DELTA_TIME * 0.5f);
			SetAction(State::CRAWL);
			_sprite->SetLeft();
		}
		else if (KEY_UP(VK_LEFT))
			SetAction(State::CROUCH);

		if (KEY_PRESS(VK_RIGHT))
		{
			_col->GetTransform()->AddVector2(RIGHT_VECTOR * _speed * DELTA_TIME * 0.5f);
			SetAction(State::CRAWL);
			_sprite->SetRight();
		}
		else if (KEY_UP(VK_RIGHT))
			SetAction(State::CROUCH);

		return;
	}
	else if (KEY_UP(VK_DOWN))
	{
		SetAction(State::IDLE);
	}

	if (KEY_PRESS(VK_LEFT))
	{
		_col->GetTransform()->AddVector2(-RIGHT_VECTOR * _speed * DELTA_TIME);
		SetAction(State::RUN);
		_sprite->SetLeft();
	}
	else if (KEY_UP(VK_LEFT))
		SetAction(State::IDLE);

	if (KEY_PRESS(VK_RIGHT))
	{
		_col->GetTransform()->AddVector2 (RIGHT_VECTOR * _speed * DELTA_TIME);
		SetAction(State::RUN);
		_sprite->SetRight();
	}
	else if (KEY_UP(VK_RIGHT))
		SetAction(State::IDLE);

}

void Player::Update()
{
	Input();

	_col->Update();
	_crouchCol->Update();
	_transform->Update();
	_actions[_curState]->Update();

	_sprite->SetCurClip(_actions[_curState]->GetCurClip());
	_sprite->Update();
}

void Player::Render()
{
	_transform->SetWorldBuffer(0);
	_sprite->Render();
	_crouchCol->Render();
	_col->Render();
}

void Player::SetAction(State state)
{
	if (_curState == state)
		return;

	_oldState = _curState;
	_actions[_oldState]->Reset();
	_actions[_oldState]->Pause();

	_curState = state;
	_actions[_curState]->Play();
}

void Player::CreateAction()
{
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/Texture/char_yellow.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = Vector2(16, 16);
	Vector2 size;
	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;

	{
		vector<Action::Clip> clips;
		for (int i = 0; i < 1; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 0.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "IDLE", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 1; i < 9; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 0.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "RUN", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 9; i < 10; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 0.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "STUN", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 2; i < 3; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 1.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "CROUCH", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 5; i < 12; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 1.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "CRAWL", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 0; i < 4; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 2.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "FLIP", Action::END);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 0; i < 8; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 9.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "JUMP", Action::END);
		_actions.push_back(action);
	}

}
