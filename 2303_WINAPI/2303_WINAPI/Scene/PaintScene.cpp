#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	//_mouseCircle = make_shared<CircleCollider>(Vector2(0,0), 50);
	//_circle = make_shared<CircleCollider>(Vector2(400, 400), 70);
	_mouseRect = make_shared<RectCollider>(Vector2(300, 300), Vector2(100, 200));
	_rect = make_shared<RectCollider>(Vector2(500, 500), Vector2(200, 100));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	//Vector2 lerpPos = LERP(_mouseCircle->GetCenter(), mousePos, 0.1f);
	//_mouseCircle->SetCenter(lerpPos);

	//if (_mouseCircle->IsCollision(_circle))
	//{
	//	_mouseCircle->SetRed();
	//	_circle->SetRed();
	//}
	//else
	//{
	//	_mouseCircle->SetGreen();
	//	_circle->SetGreen();
	//}


	Vector2 rectLerpPos = LERP(_mouseRect->GetCenter(), mousePos, 0.1f);
	_mouseRect->SetCenter(rectLerpPos);

	if (_rect->IsCollision(_mouseRect))
	{
		_rect->SetRed();
		_mouseRect->SetRed();
	}
	else
	{
		_rect->SetGreen();
		_mouseRect->SetGreen();
	}
}

void PaintScene::Render(HDC hdc)
{
	_mouseRect->Render(hdc);
	_rect->Render(hdc);
	
	//_circle->Render(hdc);
	//_mouseCircle->Render(hdc);
}
