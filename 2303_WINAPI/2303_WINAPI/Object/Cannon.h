#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void MoveByInput();

	void Fire();

private:
	shared_ptr<CircleCollider> _body;

	Vector2 _pos = CENTER;
	float _barrelLength = 100;
	float _speed = 0.2f;

	shared_ptr<Line> _barrel;
	Vector2 _direction;
	float _angle = 0.0f;

	shared_ptr<Bullet> _bullet;
};

