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

	// �̸� �����س��� 
	// ���� �Է��� ������ ����(�����Ҵ�)���� �ʰ� �̸� �����س��� Ǯ���� ���� �״ٸ� �ݺ�
	// => ������Ʈ Ǯ��
	bool _spacePress = false;
	bool _spaceUp = true;
	float _power;
	vector<shared_ptr<Bullet>> _bullets;

	int _hp = 100;
};

