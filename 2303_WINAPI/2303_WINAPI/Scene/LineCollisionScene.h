#pragma once
class LineCollisionScene : public Scene
{
public:
	LineCollisionScene();
	~LineCollisionScene();

	void Update();
	void Render();

private:
	shared_ptr<Line> _line1;
	shared_ptr<Line> _line2;

};

