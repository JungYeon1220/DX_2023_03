#pragma once
class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Update();
	void Render();

private:
	shared_ptr<Quad> _quad;
};

