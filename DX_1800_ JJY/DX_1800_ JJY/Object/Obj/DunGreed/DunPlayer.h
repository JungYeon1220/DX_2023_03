#pragma once
class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Update();
	void Render();

	void Fire();
	shared_ptr<DunBullet> SetBullet();

private:
	shared_ptr<Quad> _player;
	shared_ptr<Transform> _bowTrans;
	shared_ptr<Quad> _bow;
	shared_ptr<Transform> _bulletTrans;
	vector<shared_ptr<DunBullet>> _bullets;
};

