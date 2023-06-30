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
	shared_ptr<class DunBullet> SetBullet();

	void TakeDamage(int damage) 
	{ 
		if (_isDamaged == true)
			return;
		_hp -= damage;
		_isDamaged = true;
	}

	vector<shared_ptr<DunBullet>>& GetBullets() { return _bullets; }
	vector < shared_ptr<CircleCollider>>& GetBibles() { return _bibles; }
	shared_ptr<Transform> GetTransform() { return _col->GetTransform(); }
	shared_ptr<CircleCollider> GetCollider() { return _col; }
	int& GetHp() { return _hp; }

private:
	shared_ptr<Transform> _quadTrans;
	shared_ptr<CircleCollider> _col;
	shared_ptr<Quad> _player;

	shared_ptr<Transform> _bowSlot;
	shared_ptr<Transform> _bowTrans;
	shared_ptr<Quad> _bow;

	shared_ptr<Transform> _bulletTrans;
	vector<shared_ptr<class DunBullet>> _bullets;

	vector<shared_ptr<CircleCollider>> _bibles;
	vector<shared_ptr<Quad>> _bibleQuads;
	vector<shared_ptr<Transform>> _bibleTrans;
	shared_ptr<Transform> _bibleSlot;

	Vector2 _pos = CENTER;
	float _speed = 400.0f;
<<<<<<< HEAD

	int _hp = 10;
	bool _isDamaged = false;

	float _curTime = 0.0f;
	float _damageTime = 0.2f;
=======
>>>>>>> parent of 3c50655 (Button)
};

