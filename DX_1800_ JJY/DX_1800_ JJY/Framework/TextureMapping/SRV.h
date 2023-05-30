#pragma once
class SRV
{
public:
	SRV(wstring path);
	~SRV();

	void SetSRV(UINT slot = 0);

	Vector2 GetImageSize() { return _imageSize; }

private:
	ComPtr<ID3D11ShaderResourceView> _srv;

	Vector2 _imageSize;
};

