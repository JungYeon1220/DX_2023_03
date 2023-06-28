#pragma once
class Player
{
public:
	enum State
	{
		IDLE,
		RUN,
		STUN,
		SWIM,
		CROUCH_DOWN,
		CROUCH_UP,
		CRAWL,
		FLIP
	};

	Player();
	~Player();

	void Update();
	void Render();

	void SetAction(State state);

private:
	void CreateAction();
	State _curState = State::IDLE;
	State _oldState = State::IDLE;

	shared_ptr<CircleCollider> _col;
	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Sprite_Frame> _sprite;
};

