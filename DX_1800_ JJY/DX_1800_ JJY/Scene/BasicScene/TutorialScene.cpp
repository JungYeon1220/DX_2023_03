#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _quad = make_shared<Quad>(L"Resource/Texture/winter.png");

    _world = make_shared<MatrixBuffer>();
    _view = make_shared<MatrixBuffer>();
    _proj = make_shared<MatrixBuffer>();

    _world->Update_Resource();
    _view->Update_Resource();

    XMMATRIX temp = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0, 0);

    _proj->SetData(temp);
    _proj->Update_Resource();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{


    _quad->Update();
}

void TutorialScene::Render()
{
    _world->SetVS_Buffer(0);
    _view->SetVS_Buffer(1);
    _proj->SetVS_Buffer(2);

    _quad->Render();
}
