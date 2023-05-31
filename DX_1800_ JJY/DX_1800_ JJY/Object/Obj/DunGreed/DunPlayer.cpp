#include "framework.h"
#include "DunPlayer.h"

DunPlayer::DunPlayer()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Player.png");
	_quad->GetTransform()->SetPosition(Vector2(80.0f, 50.0f));
}

DunPlayer::~DunPlayer()
{
}

void DunPlayer::Update()
{
	_quad->Update();
}

void DunPlayer::Render()
{
	_quad->Render();
}
