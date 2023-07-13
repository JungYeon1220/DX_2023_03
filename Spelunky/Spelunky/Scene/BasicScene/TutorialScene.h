#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<class Player> _player;
	shared_ptr<RectCollider> _rect;
	shared_ptr<class Tile> _tile;
};

