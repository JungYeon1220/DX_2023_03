#pragma once
class Whip
{
public:
	Whip();
	~Whip();

	void Attack();
	void End();

	void Update();
	void Render();

	void SetLeft();
	void SetRight();

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	shared_ptr<Transform> _transform;
	shared_ptr<Sprite_Frame> _sprite;
	shared_ptr<Action> _action;

	bool _isActive = false;
};

