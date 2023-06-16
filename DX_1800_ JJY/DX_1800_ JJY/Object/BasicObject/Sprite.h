#pragma once
class Sprite : public Quad
{
protected:
	Sprite(wstring path);
	Sprite(wstring path, Vector2 size);
	virtual ~Sprite();

public:
	virtual void Update() override;
	virtual void Render() override;

	virtual void CreateVertices() override;
	virtual void CreateData(wstring path) override;

	void SetRight() { _reverseBuffer->_data.value1 = 0; }
	void SetLeft() { _reverseBuffer->_data.value1 = 1; }

protected:
	shared_ptr<ActionBuffer> _actionBuffer;
	shared_ptr<IntBuffer> _reverseBuffer;
};