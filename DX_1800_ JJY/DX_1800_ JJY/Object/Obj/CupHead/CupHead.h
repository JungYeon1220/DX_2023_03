#pragma once
class CupHead
{
public:
	enum State
	{
		IDLE,
		RUN,
		JUMP,
		ATTACK
	};

	CupHead();
	~CupHead();

	void Update();
	void Render();
	void PostRender();

	void SetLeft()
	{
		for (auto sprite : _sprites)
			sprite->SetLeft();
	}
	void SetRight()
	{
		for (auto sprite : _sprites)
			sprite->SetRight();
	}

	void Input();
	void Jump();
	void Attack();
	void SetAction(State state);

	shared_ptr<CircleCollider> GetCollider() { return _col; }
	shared_ptr<class CupBullet> GetBullet() { return _bullet; }

	bool IsFalling() { return _isFalling; }
	void SetIsFalling(bool value) { _isFalling = value; }
	void Grounded() { _isFalling = false; }
	void AttackEnd();

private:
	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::LOOP, CallBack callBack = nullptr);

	shared_ptr<CircleCollider> _col;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Sprite_Clip>> _sprites;
	shared_ptr<class CupBullet> _bullet;

	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	bool _isFalling = false;
	bool _isAttack = false;

	float _jumpPower = 0.0f;
	float _maxFalling = 800.0f;

	float _speed = 300.0f;

	shared_ptr<FilterBuffer> _filterBuffer;
};

