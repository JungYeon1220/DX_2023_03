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

	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::LOOP, CallBack callBack = nullptr);

	void SetAction(State state);

private:
	shared_ptr<CircleCollider> _col;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Sprite_Clip>> _sprites;

	State _state = State::IDLE;

	bool _isFalling;
	bool _isAttack;

	float _speed = 300.0f;
};

