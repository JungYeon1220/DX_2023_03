#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _quad = make_shared<Quad>(L"Resource/Texture/winter.png");
	_quadTrans = make_shared<Transform>();

	_quadTrans->SetPosition(CENTER);
	_quadTrans->SetScale(Vector2(0.5f, 0.5f));
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad->Update();
	_quadTrans->Update();
}

void TutorialScene::Render()
{
	_quadTrans->SetWorldBuffer(0);
	_quad->Render();
}
