#pragma once
class CupMonster
{
public:
	CupMonster();
	~CupMonster();

	void Update();
	void Render();

	shared_ptr<CircleCollider> GetCollider() { return _col; }
	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::LOOP, CallBack callBack = nullptr);

private:
	shared_ptr<CircleCollider> _col;

	shared_ptr<Transform> _transform;
	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Sprite_Clip>> _sprites;
};

