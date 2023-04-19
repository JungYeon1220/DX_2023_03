#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(Vector2(0,0), 50);
	_rect = make_shared<RectCollider>(Vector2(0, 0), 200, 100);
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerpPos = LERP(_circle->GetCenter(), mousePos, 0.1f);
	_circle->SetCenter(lerpPos);

	Vector2 rectLerpPos = LERP(_rect->GetCenter(), mousePos, 0.05f);
	_rect->SetCenter(rectLerpPos);
}

void PaintScene::Render(HDC hdc)
{
	_rect->Render(hdc);
	_circle->Render(hdc);
}
