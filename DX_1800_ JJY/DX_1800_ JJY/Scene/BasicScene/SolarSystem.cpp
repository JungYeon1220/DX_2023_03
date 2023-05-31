#include "framework.h"
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	// ����1
	// Planet�̶�� Ŭ���� ����
	// �¾�, ����, ��

	// _sun = make_shared<Planet>(L"Resource/Texture/sun.png")
	_sun = make_shared<Planet>(L"sun");
	_earth = make_shared<Planet>(L"earth");
	_moon = make_shared<Planet>(L"moon");

	_sun->SetPosition(CENTER);
	_sun->SetScale(Vector2(0.3f, 0.3f));
	_earth->SetScale(Vector2(0.3f, 0.3f));
	_moon->SetScale(Vector2(0.3f, 0.3f));
	_earth->SetParent(_sun->GetOrbit());
	_earth->SetPosition(Vector2(800.0f, 0.0f));
	_moon->SetParent(_earth->GetOrbit());
	_moon->SetPosition(Vector2(600.0f, 0.0f));
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::Update()
{
	_sun->SetPosition(mousePos);

	_sun->Update();
	_earth->Update();
	_moon->Update();
}

void SolarSystem::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();
}
