#pragma once
class ColliderScene : public Scene
{
public:
	ColliderScene();
	virtual ~ColliderScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Collider> _rectCollider;
	shared_ptr<Collider> _rectCollider2;
	shared_ptr<Collider> _circleCollider;
	shared_ptr<Collider> _circleCollider2;

	vector<shared_ptr<Collider>> _colliders;
};

