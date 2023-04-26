#include "framework.h"
#include "Arkanoid.h"

Arkanoid::Arkanoid()
{
	_bar = make_shared<Bar>();
	_ball = make_shared<Ball>();
	for (int i = 0; i < 3; i++)
	{
		shared_ptr<Brick> brick = make_shared<Brick>();
		_bricks.push_back(brick);
	}
	_bricks[0]->SetPosition(CENTER);
	_bricks[1]->SetPosition(Vector2(CENTER.x - 60, CENTER.y));
	_bricks[2]->SetPosition(Vector2(CENTER.x + 60, CENTER.y));
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

	for (auto brick : _bricks)
	{
		if (_ball->Collision(brick))
			break;
	}

	for (auto brick : _bricks)
	{
		brick->Update();
	}
	_bar->Update();
	_ball->Update();
}

void Arkanoid::Render(HDC hdc)
{
	_bar->Render(hdc);
	_ball->Render(hdc);
	for (auto brick : _bricks)
	{
		brick->Render(hdc);
	}
}
