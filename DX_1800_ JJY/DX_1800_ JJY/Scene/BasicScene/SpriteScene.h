#pragma once
class SpriteScene : public Scene
{
public:
	SpriteScene();
	virtual ~SpriteScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CreateAction();

	void EndEvent() { _event = "End"; }
	void EndEventNumber(int num) { _eventNumber = num; }

private:
	string _event = "Not End";
	int _eventNumber = 0;

	shared_ptr<class Zelda> _zelda;

	shared_ptr<Action> _action;
};

