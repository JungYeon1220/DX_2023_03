#pragma once
class CannonScene : public Scene
{
public:
	CannonScene();
	virtual ~CannonScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;

};

