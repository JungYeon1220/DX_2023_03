#include "framework.h"
#include "SpriteScene.h"

#include "../../Object/Obj/Zelda/Zelda.h"

SpriteScene::SpriteScene()
{
	CreateAction();
	_zelda = make_shared<Zelda>();
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_action->Update();
	_zelda->Update();
}

void SpriteScene::Render()
{
	_zelda->GetSprite()->SetCurClip(_action->GetCurClip());
	_zelda->Render();
}

void SpriteScene::PostRender()
{
	ImGui::Text(_event.c_str());
	ImGui::Text("Event Number : %d", _eventNumber);
}

void SpriteScene::CreateAction()
{
	vector<Action::Clip> clips;
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/Texture/zelda.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = Vector2(10, 8);
	Vector2 size;
	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;

	// ¶Ù´Â ¸ð¼Ç
	for(int i = 0; i < 10; i++)
	{
		Vector2 startPos = Vector2((i * imageSize.x) / maxFrame.x, imageSize.y * 4.0f / maxFrame.y);
		Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
		clips.push_back(clip);
	}

	_action = make_shared<Action>(clips, "F_RUN", Action::Type::END);
	_action->Play();
	_action->SetEndEvent(std::bind(&SpriteScene::EndEvent, this));
}
