#pragma once
class Sprite_Frame : public Sprite
{
public:
	// TODO: 분리하기
	Sprite_Frame(wstring path, Vector2 maxFrame); // -> Frame 별로 잘 나뉘어져있을 때
	Sprite_Frame(wstring path, Vector2 maxFrame, Vector2 size); // -> Action을 이용하여 클립으로 세팅할 때
	virtual ~Sprite_Frame();

	virtual void Update() override;
	virtual void Render() override;

	void SetCurClip(Vector2 frame);

private:
	Vector2 _maxFrame;
};

