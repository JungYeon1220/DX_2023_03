#pragma once
class Camera
{
private:
	Camera();
	~Camera();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Camera();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Camera* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		
		return nullptr;
	}

private:
	static Camera* _instance;

};

