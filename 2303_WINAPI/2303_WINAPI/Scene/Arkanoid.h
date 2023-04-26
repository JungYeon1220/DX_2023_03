#pragma once
class Arkanoid : public Scene
{
public:
	Arkanoid();
	virtual ~Arkanoid();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Bar> _bar;
	shared_ptr<Ball> _ball;
	vector<shared_ptr<Brick>> _bricks;

};

