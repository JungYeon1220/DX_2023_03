#pragma once
class Planet
{
public:
	Planet(wstring name);
	~Planet();

	void Update();
	void Render();

	void SetRotation(float speed) { _rotationSpeed = speed; }
	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetParent(shared_ptr<Transform> parent);

	shared_ptr<Transform> GetTransform() { return _planet->GetTransform(); }
	shared_ptr<Quad> GetQuad() { return _planet; }
	shared_ptr<Transform> GetOrbit() { return _orbit; }

private:
	float _rotationSpeed = 0.0003f;

	shared_ptr<Quad> _planet;
	shared_ptr<Transform> _orbit;
};
