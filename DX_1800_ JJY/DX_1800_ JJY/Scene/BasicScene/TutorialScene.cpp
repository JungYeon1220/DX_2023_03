#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
    _quad = make_shared<Quad>(L"Resource/Texture/winter.png");
	_quadTrans = make_shared<Transform>();
	_quad->SetPS(ADD_PS(L"Shader/FilterPS.hlsl"));

	_quadTrans->SetPosition(CENTER);
	_quadTrans->SetScale(Vector2(0.5f, 0.5f));

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->_data.imageSize = _quad->GetImageSize();
	_filterBuffer->_data.radialCenter = { 0.5f, 0.5f };

	_effect = make_shared<Effect>("Hit", L"Resource/Texture/hit_4x2.png", Vector2(4, 2), Vector2(100, 100), 0.1f);
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_quad->Update();
	_quadTrans->Update();
	_filterBuffer->Update_Resource();

	_effect->Update();
}

void TutorialScene::Render()
{
	_quadTrans->SetWorldBuffer(0);
	_filterBuffer->SetPS_Buffer(0);
	_quad->Render();

	if (KEY_DOWN(VK_LBUTTON))
	{
		_effect->Play(MOUSE_POS);
	}

	_effect->Render();
}

void TutorialScene::PostRender()
{
	ImGui::SliderInt("selected", &_filterBuffer->_data.selected, 0, 5);
	ImGui::SliderInt("value1", &_filterBuffer->_data.value1, 0, 300);
	ImGui::SliderInt("value2", &_filterBuffer->_data.value2, 0, 300);
	ImGui::SliderInt("value3", &_filterBuffer->_data.value3, 0, 300);
}
