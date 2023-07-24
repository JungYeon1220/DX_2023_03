#pragma once
class TileMapScene : public Scene
{
public:
	TileMapScene();
	~TileMapScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;
private:
	
};

