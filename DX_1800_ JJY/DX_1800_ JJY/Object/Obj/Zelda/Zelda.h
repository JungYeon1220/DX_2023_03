#pragma once
class Zelda
{
public:
	Zelda();
	~Zelda();

	void Update();
	void Render();

	shared_ptr<Sprite> GetSprite() { return _sprite; }

private:
	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;
};

