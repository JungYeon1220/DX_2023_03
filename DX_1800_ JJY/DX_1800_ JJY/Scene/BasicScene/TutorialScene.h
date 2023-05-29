#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Quad> _quad;

	float _x = WIN_WIDTH / 2;
	float _y = WIN_HEIGHT / 2;

	float _size = 1.0f;

	float _angle = 0.0f;

	shared_ptr<MatrixBuffer> _world;
	shared_ptr<MatrixBuffer> _view;
	shared_ptr<MatrixBuffer> _proj;
};

