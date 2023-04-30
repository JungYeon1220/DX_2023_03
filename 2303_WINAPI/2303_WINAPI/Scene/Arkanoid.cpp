#include "framework.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();

	_stage = make_shared<Stage>();

	_wall1 = make_shared<Line>(Vector2((int)CENTER.x - BRICKSIZEX * 6, 0), Vector2((int)CENTER.x - BRICKSIZEX * 6, WIN_HEIGHT));
	_wall2 = make_shared<Line>(Vector2((int)CENTER.x + BRICKSIZEX * 6, 0), Vector2((int)CENTER.x + BRICKSIZEX * 6, WIN_HEIGHT));
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	if (_ball->_isStart == false)
	{
		_ball->SetPosition(Vector2(_bar->GetPosition().x + 10, _bar->GetPosition().y - _bar->GetSize().y * 0.5f - _ball->GetRadius() + 1));
	}

	_ball->Collision(_bar);
	for (auto brickArr : _stage->GetBricks())
	{
		bool hit = false;
		for (auto brick : brickArr)
		{
			hit = _ball->Collision(brick);
			if (hit)
				break;
		}
		if (hit)
			break;
	}

	_bar->Update();
	_ball->Update();
	_wall1->Update();
	_wall2->Update();
	_stage->Update();
}

void Arkanoid::Render(HDC hdc)
{
	_bar->Render(hdc);
	_ball->Render(hdc);
	_stage->Render(hdc);

	_wall1->Render(hdc);
	_wall2->Render(hdc);
}
