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

	// 인력사무소장
	// 외주를 맡기고 실질적인 노가다 대표 뽑기
	// 컴퓨터의 하드웨어 기능 점검, 리소스 할당 하는 얘들을 뽑아주는 얘
	ComPtr<ID3D11Device> device;

	// 연출감독
	// 세트장을 실질적으로 꾸며주는 연출가
	// 렌더링 대상 결정(어따 그릴지 결정)
	// => 리소스를 그래픽 파이프라인에 바인딩, 리소스 할당
	ComPtr<ID3D11DeviceContext> deviceContext; // DC

	// DX의 인터페이스로써 1개이상의 표면을 포함할 수 있다.
	// 각각의 표면(버퍼, 텍스쳐)을 출력하기전에 데이터를 보관한다.
	ComPtr<IDXGISwapChain> swapChain;

	// 후면 버퍼를 가리키는 포인터
	// 후면 버퍼(지금 당장 그릴 곳)
	// view ... 포인터
	ComPtr<ID3D11RenderTargetView> renderTargetView;
};

