#pragma once
class LIneScene : public Scene
{
public:
	LIneScene();
	virtual ~LIneScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Line> _floorLine;
	shared_ptr<Line> _mouseLine;
	shared_ptr<Line> _shadowLine;

};

