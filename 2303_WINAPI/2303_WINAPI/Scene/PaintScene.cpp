#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(Vector2(0,0), 50);
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerpPos = LERP(_circle->GetCenter(), mousePos, 0.1f);
	_circle->SetCenter(lerpPos);
}

void PaintScene::Render(HDC hdc)
{
	_circle->Render(hdc);
}
