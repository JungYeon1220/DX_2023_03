#pragma once

class RectCollider;
class CircleCollider;

class Collider
{
public:
	enum class Type
	{
		NONE,
		CIRCLE,
		RECT
	};

	Collider(Vector2 center);
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	void SetCenter(Vector2 center) { _center = center; }
	const Vector2& GetCenter() { return _center; }

	bool IsCollision(shared_ptr<Collider> col);
	virtual bool IsCollision(const Vector2& pos) abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> other) abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) abstract;

	void SetGreen() { _curPenIndex = 0; }
	void SetRed() { _curPenIndex = 1; }

protected:
	Type _type;

	void CreatePens();
	void CreateBrushes();

	int _curBrushIndex;
	int _curPenIndex;
	vector<HPEN> _pens;
	vector<HBRUSH> _brushes;

	Vector2 _center = { 0.0f, 0.0f };
};

