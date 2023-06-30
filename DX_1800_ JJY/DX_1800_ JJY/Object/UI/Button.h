#pragma once
class Button
{
public:
	Button(wstring path, Vector2 size);
	~Button();

	void Update();
	void PostRender();

	void SetPosition(Vector2 pos) { _col->GetTransform()->SetPosition(pos); }
	void SetEvent(CallBack2 fn) { _event = fn; }
	void SetPS(wstring path);

private:
	shared_ptr<RectCollider> _col;
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _quadTransform;

	CallBack2 _event;

	shared_ptr<ButtonBuffer> _buttonBuffer;
};

