#pragma once
class CupBullet
{
public:
	CupBullet();
	~CupBullet();

	void Update();
	void Render();

	void SetPosition(Vector2 pos) { _col->GetTransform()->SetPosition(pos); }
	void SetDerection(Vector2 dir) { _direction = dir.NorMalVector2(); _col->GetTransform()->SetAngle(_direction.Angle()); }

	bool _isActive;

private:
	void CreateAction(string name, float speed = 0.1f, Action::Type type = Action::LOOP, CallBack callBack = nullptr);

	shared_ptr<Sprite_Clip> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Transform> _transform;
	shared_ptr<CircleCollider> _col;

	Vector2 _direction = Vector2();
	float _speed = 500.0f;

};

