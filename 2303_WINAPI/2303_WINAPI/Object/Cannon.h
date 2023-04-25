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

	int& GetHp() { return _hp; }
	void TakeDamage(int amount) { _hp -= amount; }

	shared_ptr<Bullet> SetBullet();
	void SetPosition(const Vector2& pos) { _pos = pos; }

	vector<shared_ptr<Bullet>>& GetBullets() { return _bullets; }

	shared_ptr<CircleCollider> GetBody() { return _body; }

	bool _isDead() { return _hp <= 0; }

	bool _isControl = true;
private:

	shared_ptr<CircleCollider> _body;
	Vector2 _pos = CENTER;
	float _barrelLength = 100;
	float _speed = 1.0f;

	shared_ptr<Line> _barrel;
	Vector2 _direction;
	float _angle = 0.0f;

	// 미리 생성해놓고 
	// 내가 입력할 때마다 생성(동적할당)하지 않고 미리 생성해놓은 풀에서 껐다 켰다를 반복
	// => 오브젝트 풀링
	bool _spacePress = false;
	bool _spaceUp = true;
	float _power;
	vector<shared_ptr<Bullet>> _bullets;

	int _hp = 100;
};

