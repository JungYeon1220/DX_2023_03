#include "framework.h"
#include "Program.h"

#include "../Scene/BasicScene/TutorialScene.h"

Program::Program()
{
	_curScene = make_shared<TutorialScene>();
}

Program::~Program()
{
}

void Program::Update()
{
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	_curScene->Render();

	Device::GetInstance()->Present();
}
