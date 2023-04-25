#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPosition(Vector2 pos) { _pos = pos; }
	void SetDirection(Vector2 dir) { _direction = dir.NormalVector2(); }

	float GetRadius() { return dynamic_pointer_cast<CircleCollider>(_circle)->GetRadius(); }

	void Collision(shared_ptr<Bar> bar);

	bool _isStart = false;
private:
	shared_ptr<Collider> _circle;
	Vector2 _pos;

	float _speed = 4.5f;
	Vector2 _direction = Vector2(0, 0);


};

