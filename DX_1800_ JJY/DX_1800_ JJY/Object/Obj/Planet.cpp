#include "framework.h"
#include "Planet.h"

Planet::Planet(wstring name)
{
	wstring path = L"Resource/Texture/" + name + L".png";
	_planet = make_shared<Quad>(path);
	_trans = make_shared<Transform>();
	_orbit = make_shared<Transform>();
}

Planet::~Planet()
{
}

void Planet::Update()
{
	_trans->AddAngle(_rotationSpeed);
	_orbit->AddAngle(_rotationSpeed * 1.5f);
	_planet->Update();
	_orbit->Update();
	_trans->Update();
}

void Planet::Render()
{
	_trans->SetWorldBuffer(0);
	_planet->Render();
}

void Planet::SetPosition(Vector2 pos)
{
	_trans->SetPosition(pos);
	_orbit->SetPosition(pos);
}

void Planet::SetScale(Vector2 scale)
{
	_trans->SetScale(scale);
	_orbit->SetScale(scale);
}

void Planet::SetParent(shared_ptr<Transform> parent)
{
	_trans->SetParent(parent);
	_orbit->SetParent(parent);
}