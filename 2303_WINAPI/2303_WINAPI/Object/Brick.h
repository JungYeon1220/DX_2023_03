#pragma once
class Brick
{
public:
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);

private:
	shared_ptr<Collider> _rect;

};

