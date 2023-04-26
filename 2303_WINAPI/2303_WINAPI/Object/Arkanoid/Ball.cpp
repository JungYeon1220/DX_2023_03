#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(Vector2(), 8);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if((GetAsyncKeyState(VK_SPACE)))
		_isStart = true;

	if (_isStart == true)
	{
		_pos += _direction * _speed;
	}

	if (_pos.x > CENTER.x + BRICKSIZEX * 6 - GetRadius() || _pos.x < CENTER.x - BRICKSIZEX * 6 + GetRadius())
		_direction.x = -_direction.x;
	if (_pos.y < 0 + GetRadius())
		_direction.y = -_direction.y;
	if (_pos.y > WIN_HEIGHT + GetRadius())
	{
		_isStart = false;
	}

	_circle->SetCenter(_pos);
	_circle->Update();
}

void Ball::Render(HDC hdc)
{
	_circle->Render(hdc);
}

void Ball::Collision(shared_ptr<Bar> bar)
{
	if (_circle->GetCenter().y < bar->GetTop() && _circle->IsCollision(bar->GetRect()))
		SetDirection(_circle->GetCenter() - bar->GetPosition());
}

bool Ball::Collision(shared_ptr<Brick> brick)
{
	if (_circle->IsCollision(brick->GetRect()) && brick->_isActive == true)
	{
		if (_circle->GetCenter().x > brick->GetRect()->Left() - 3 && _circle->GetCenter().x < brick->GetRect()->Right() + 3)
		{
			_direction.y = -_direction.y;
		}
		else if (_circle->GetCenter().y > brick->GetRect()->Top() - 3 && _circle->GetCenter().y < brick->GetRect()->Bottom() + 3)
		{
			_direction.x = -_direction.x;
		}
		else
		{
			bool xPos = _pos.x > brick->GetRect()->GetCenter().x;
			bool yPos = _pos.y > brick->GetRect()->GetCenter().y;

			Vector2 normal = Vector2(1 - (2 * xPos), 1 - (2 * yPos)).NormalVector2();

			_direction = _direction - normal * _direction.Dot(normal) * 2;
		}

		brick->_isActive = false;
		return true;
	}

	return false;
}
