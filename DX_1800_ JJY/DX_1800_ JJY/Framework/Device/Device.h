#pragma once
class Device
{
private:
	Device();
	~Device();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Device();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Device* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		else
			return nullptr;
	}

	ComPtr<ID3D11Device> GetDevice() { return device; }
	ComPtr<ID3D11DeviceContext> GetDC() { return deviceContext; }

	void Clear();
	void Present();

private:
	void CreateDeviceAndSwapChain();
	void CreateDoubleBuffer();

	static Device* _instance;

	// �η»繫����
	// ���ָ� �ñ�� �������� �밡�� ��ǥ �̱�
	// ��ǻ���� �ϵ���� ��� ����, ���ҽ� �Ҵ� �ϴ� ����� �̾��ִ� ��
	ComPtr<ID3D11Device> device;

	// ���Ⱘ��
	// ��Ʈ���� ���������� �ٸ��ִ� ���Ⱑ
	// ������ ��� ����(��� �׸��� ����)
	// => ���ҽ��� �׷��� ���������ο� ���ε�, ���ҽ� �Ҵ�
	ComPtr<ID3D11DeviceContext> deviceContext; // DC

	// DX�� �������̽��ν� 1���̻��� ǥ���� ������ �� �ִ�.
	// ������ ǥ��(����, �ؽ���)�� ����ϱ����� �����͸� �����Ѵ�.
	ComPtr<IDXGISwapChain> swapChain;

	// �ĸ� ���۸� ����Ű�� ������
	// �ĸ� ����(���� ���� �׸� ��)
	// view ... ������
	ComPtr<ID3D11RenderTargetView> renderTargetView;
};

