#pragma once
class Sprite_Clip : public Sprite
{
public:
	// TODO: �и��ϱ�
	Sprite_Clip(wstring path); // -> Frame ���� �� ������������ ��
	Sprite_Clip(wstring path, Vector2 size); // -> Action�� �̿��Ͽ� Ŭ������ ������ ��
	virtual ~Sprite_Clip();

	virtual void Update() override;
	virtual void Render() override;

	void SetCurClip(Action::Clip clip);

private:
};

