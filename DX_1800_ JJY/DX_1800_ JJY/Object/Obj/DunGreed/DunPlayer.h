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
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _trans;
	shared_ptr<Quad> _bow;
	shared_ptr<DunBullet> _bullet;
	shared_ptr<Transform> _muzzle;
	vector<shared_ptr<DunBullet>> _bullets;

	bool _mousePress = false;
	bool _mouseUp = true;
};

