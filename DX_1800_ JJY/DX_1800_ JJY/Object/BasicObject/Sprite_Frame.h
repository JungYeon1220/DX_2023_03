#pragma once
class Sprite_Frame : public Sprite
{
public:
	// TODO: �и��ϱ�
	Sprite_Frame(wstring path, Vector2 maxFrame); // -> Frame ���� �� ������������ ��
	Sprite_Frame(wstring path, Vector2 maxFrame, Vector2 size); // -> Action�� �̿��Ͽ� Ŭ������ ������ ��
	virtual ~Sprite_Frame();

	virtual void Update() override;
	virtual void Render() override;

	void SetCurClip(Vector2 frame);

private:
	Vector2 _maxFrame;
};

