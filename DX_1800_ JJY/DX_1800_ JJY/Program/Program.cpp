#include "framework.h"
#include "Program.h"

#include "../Scene/BasicScene/TutorialScene.h"
#include "../Scene/BasicScene/SolarSystem.h"
#include "../Scene/BasicScene/DunGreed.h"
#include "../Scene/BasicScene/ColliderScene.h"
#include "../Scene/BasicScene/SpriteScene.h"
#include "../Scene/BasicScene/ZeldaScene.h"
#include "../Scene/BasicScene/CupHeadScene.h"

Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_curScene = make_shared<TutorialScene>();

	Timer::GetInstance()->LockFPS(60.0f);
}

Program::~Program()
{
}

void Program::Update()
{
	Timer::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	CAMERA->Update();
	_curScene->Update();

	EFFECT->Update();
	SOUND->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	CAMERA->SetViewBuffer();
	CAMERA->SetProjectionBuffer();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA->SetState();
	_curScene->Render();
	EFFECT->Render();

	//ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());
	//ImGui::Text("DeltaTime : %1f", Timer::GetInstance()->GetDeltaTime());
	//ImGui::Text("RunTime : %1f", Timer::GetInstance()->GetRunTime());
	CAMERA->PostRender();
	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
