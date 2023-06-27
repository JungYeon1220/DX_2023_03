#include "framework.h"
#include "Player.h"

Player::Player()
{
	_col = make_shared<CircleCollider>(50.0f);
	_transform = make_shared<Transform>();
	_sprite = make_shared<Sprite_Frame>(L"Resource/Texture/char_yellow.png", Vector2(16, 15));

	_transform->SetParent(_col->GetTransform());

}

Player::~Player()
{
}

void Player::CreateAction()
{
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/Texture/char_yellow.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = Vector2(16, 15);
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
		for (int i = 10; i < 16; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 0.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "SWIM", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 0; i < 3; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 1.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "CROUCH_DOWN", Action::LOOP);
		_actions.push_back(action);
	}

	{
		vector<Action::Clip> clips;
		for (int i = 2; i < 5; i++)
		{
			Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 1.0f / maxFrame.y);
			Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
			clips.push_back(clip);
		}

		shared_ptr<Action> action = make_shared<Action>(clips, "CROUCH_UP", Action::LOOP);
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

}
