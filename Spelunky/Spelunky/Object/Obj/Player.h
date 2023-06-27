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
	};

	Player();
	~Player();

private:
	void CreateAction();
	State _state = State::IDLE;

	shared_ptr<CircleCollider> _col;
	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Sprite_Frame> _sprite;
};

