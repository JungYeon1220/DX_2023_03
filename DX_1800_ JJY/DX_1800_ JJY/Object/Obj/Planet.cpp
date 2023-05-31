#include "framework.h"
#include "Planet.h"

Planet::Planet(wstring name)
{
	wstring path = L"Resource/Texture/" + name + L".png";
	_planet = make_shared<Quad>(path);
	_orbit = make_shared<Transform>();
}

Planet::~Planet()
{
}

void Planet::Update()
{
	_planet->GetTransform()->AddAngle(_rotationSpeed);
	_orbit->AddAngle(_rotationSpeed * 1.5f);
	_planet->Update();
	_orbit->Update();
}

void Planet::Render()
{
	_planet->Render();
}

void Planet::SetPosition(Vector2 pos)
{
	_planet->GetTransform()->SetPosition(pos);
	_orbit->SetPosition(pos);
}

void Planet::SetScale(Vector2 scale)
{
	_planet->GetTransform()->SetScale(scale);
	_orbit->SetScale(scale);
}

void Planet::SetParent(shared_ptr<Transform> parent)
{
	_planet->GetTransform()->SetParent(parent);
	_orbit->SetParent(parent);
}