#pragma once
class SpriteScene : public Scene
{
public:
	SpriteScene();
	virtual ~SpriteScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<class Zelda> _zelda;
};

