#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void SetDirection(Vector2 dir) { _direction = dir.NormalVector2(); }
	void SetPos(const Vector2& pos) { _circle->SetCenter(pos); }

private:
	shared_ptr<CircleCollider> _circle;

	Vector2 _direction = Vector2();
	Vector2 _pos = Vector2();
};

