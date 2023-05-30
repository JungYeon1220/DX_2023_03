#include "framework.h"
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	// 과제1
	// Planet이라는 클래스 구현
	// 태양, 지구, 달

	// _sun = make_shared<Planet>(L"Resource/Texture/sun.png")


	_sun = make_shared<Quad>(L"Resource/Texture/sun.png");
	_earth = make_shared<Quad>(L"Resource/Texture/earth.png");
	_moon = make_shared<Quad>(L"Resource/Texture/moon.png");
	_earthOrbit = make_shared<Transform>();
	_moonOrbit = make_shared<Transform>();

	_sun->GetTransform()->SetPosition(CENTER);

	_sun->GetTransform()->SetScale(Vector2(0.3f, 0.3f));
	_earth->GetTransform()->SetScale(Vector2(0.3f, 0.3f));
	_moon->GetTransform()->SetScale(Vector2(0.3f, 0.3f));

	_earthOrbit->SetParent(_sun->GetTransform());
	_earth->GetTransform()->SetParent(_earthOrbit);
	_earth->GetTransform()->SetPosition(Vector2(900.0f, 0.0f));

	_moonOrbit->SetParent(_earth->GetTransform());
	_moon->GetTransform()->SetParent(_moonOrbit);
	_moon->GetTransform()->SetPosition(Vector2(700.0f, 0.0f));
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::Update()
{
	_sun->GetTransform()->AddAngle(0.0025f);
	_earthOrbit->AddAngle(-0.0022f);

	_earth->GetTransform()->AddAngle(0.015f);
	_moonOrbit->AddAngle(-0.0135f);

	_sun->Update();
	_earthOrbit->Update();
	_earth->Update();
	_moonOrbit->Update();
	_moon->Update();
}

void SolarSystem::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();
}
