#pragma once
class Player
{
public:
	enum State
	{
		IDLE,
		RUN,
		STUN,
		CROUCH,
		CRAWL,
		FLIP,
		JUMP,
		ATTACK
	};

	Player();
	~Player();

	void Input();
	void Jump();
	void Attack();

	void Update();
	void Render();

	void SetAction(State state);
	void SetIdle()
	{
		if (_isAttack == true)
			return;
		SetAction(State::IDLE);
	}
	void EndAttack();

	shared_ptr<RectCollider> GetCollider() { return _col; }
	bool& IsFalling() { return _isFalling; }

private:
	void CreateAction();
	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	shared_ptr<RectCollider> _col;
	shared_ptr<RectCollider> _crouchCol;
	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Sprite_Frame> _sprite;

	shared_ptr<class Whip> _whip;

	float _speed = 300.0f;
	bool _isCrouching = false;

	bool _isFalling = false;
	float _jumpPower = 0.0f;
	float _maxFalling = 800.0f;

	bool _isAttack = false;
};

