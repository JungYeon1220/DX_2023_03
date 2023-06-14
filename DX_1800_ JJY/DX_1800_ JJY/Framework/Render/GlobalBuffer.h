#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:
	struct  Data
	{
		XMMATRIX matrix;
	};

	MatrixBuffer()
	: ConstantBuffer(&_data, sizeof(_data))
	{
		_data.matrix = XMMatrixIdentity();
	}

	virtual ~MatrixBuffer() {}

	void SetData(XMMATRIX matrix)
	{
		matrix = XMMatrixTranspose(matrix);
		_data.matrix = matrix;
	}

	Data _data;
};

class ColorBuffer : public ConstantBuffer
{
public:
	struct  Data
	{
		XMFLOAT4 color;
	};

	ColorBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
		_data.color = XMFLOAT4();
	}

	virtual ~ColorBuffer() {}

	void SetColor(XMFLOAT4 color)
	{
		_data.color = color;
	}

	Data _data;
};

class FrameBuffer : public ConstantBuffer
{
public:
	struct  Data
	{
		XMFLOAT2 maxFrame = XMFLOAT2();
		XMFLOAT2 curFrame = XMFLOAT2();
	};

	FrameBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~FrameBuffer() {}

	Data _data;
};

class ActionBuffer : public ConstantBuffer
{
public:
	struct  Data
	{
		Vector2 startPos;
		Vector2 size;
		Vector2 imageSize;
		int padding[2];
	};

	ActionBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~ActionBuffer() {}

	Data _data;
};