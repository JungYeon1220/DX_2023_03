#pragma once
class CupBG
{
public:
	CupBG();
	~CupBG();

	void Update();
	void Render();

	void SetPosition(Vector2 pos) { _col->GetTransform()->SetPosition(pos); }
	shared_ptr<RectCollider> GetCollider() { return _col; }

	bool Block(shared_ptr<CircleCollider> col) {}

private:
	shared_ptr<Transform> _transform;
	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _col;
};

