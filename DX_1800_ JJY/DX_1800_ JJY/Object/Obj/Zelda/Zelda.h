#pragma once
class Zelda
{
public:
	Zelda();
	~Zelda();

	void Update();
	void Render();

private:
	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;

};

