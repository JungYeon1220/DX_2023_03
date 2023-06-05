#pragma once
class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Update();
	void Render();

	void Move();

	void Fire();
	shared_ptr<DunBullet> SetBullet();

private:
	shared_ptr<Quad> _player;
	shared_ptr<Transform> _bowTrans;
	shared_ptr<Quad> _bow;
	shared_ptr<Transform> _bulletTrans;
	vector<shared_ptr<DunBullet>> _bullets;

	Vector2 _pos = Vector2();
	float _speed = 0.5f;
	
};

