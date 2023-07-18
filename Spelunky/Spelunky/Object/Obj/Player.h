#pragma once
class Player
{
public:
	enum State
	{
		IDLE,
		RUN,
		DEAD,
		LAY_DOWN,
		CRAWL,
		STUN,
		JUMP,
		ATTACK,
		CLIMB_RADDER
	};

	Player();
	~Player();

	void Input();
	void Jump();
	void Attack();
	void ClimbRadder();

	void Update();
	void Render();
	void PostRender();

	void SetAction(State state);
	void SetIdle()
	{
		if (_isAttack == true)
			return;
		SetAction(State::IDLE);
	}
	void EndAttack();

	shared_ptr<RectCollider> GetCollider() { return _col; }
	shared_ptr<CircleCollider> GetFeetCollider() { return _feetCol; }
	shared_ptr<CircleCollider> GetHeadCollider() { return _headCol; }
	float& GetJumpPower() { return _jumpPower; }
	bool& IsFalling() { return _isFalling; }
	bool& isClimb() { return _isClimb; }

private:
	void CreateAction();
	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	shared_ptr<RectCollider> _col;
	shared_ptr<RectCollider> _crouchCol;
	shared_ptr<CircleCollider> _feetCol;
	shared_ptr<CircleCollider> _headCol;
	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Sprite_Frame> _sprite;

	shared_ptr<class Whip> _whip;

	float _speed = 300.0f;
	bool _isLaying = false;

	bool _isFalling = false;
	float _jumpPower = 0.0f;
	float _maxFalling = 700.0f;

	bool _isAttack = false;
	bool _isClimb = false;

	bool _canClimb = true;
	float _climbTime = 0.0f;
};

