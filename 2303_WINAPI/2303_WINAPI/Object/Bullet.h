#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void SetDirection(Vector2 dir) { _direction = dir.NormalVector2(); }
	void SetPos(const Vector2& pos) { _pos = pos; }

	void SetActive(bool value) { _isActive = value; }
	bool IsActive() { return _isActive; }

	bool AttackCannon(shared_ptr<class Cannon> cannon);

private:
	bool _isActive = false;
	shared_ptr<Collider> _circle;

	Vector2 _direction = Vector2();
	Vector2 _pos = Vector2();
	float _speed = 10.0f;

	int _damage = 10;
};

