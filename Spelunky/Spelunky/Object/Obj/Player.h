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
		JUMP
	};

	Player();
	~Player();

	void Input();

	void Update();
	void Render();

	void SetAction(State state);
	void SetIdle() { SetAction(State::IDLE); }

private:
	void CreateAction();
	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	shared_ptr<RectCollider> _col;
	shared_ptr<RectCollider> _crouchCol;
	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Sprite_Frame> _sprite;

	float _speed = 300.0f;
	bool _isCrouching = false;

	float _curJumpPower = 0.0f;
	float _maxJumpPower = 500.0f;
};

