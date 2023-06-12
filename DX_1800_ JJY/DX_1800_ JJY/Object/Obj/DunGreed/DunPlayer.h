#pragma once
class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Update();
	void Render();

	void Move();
	void SetPosition(Vector2 pos) { _pos = pos; }

	void Fire();
	shared_ptr<DunBullet> SetBullet();

	vector<shared_ptr<DunBullet>>& GetBullets() { return _bullets; }
	shared_ptr<Transform> GetTransform() { return _player->GetTransform(); }

private:
	shared_ptr<Quad> _player;
	shared_ptr<Transform> _bowTrans;
	shared_ptr<Quad> _bow;
	shared_ptr<Transform> _bulletTrans;
	vector<shared_ptr<DunBullet>> _bullets;

	Vector2 _pos = CENTER;
	float _speed = 400.0f;
	
};

