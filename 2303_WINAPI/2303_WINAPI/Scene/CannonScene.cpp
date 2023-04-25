#include "framework.h"
#include "CannonScene.h"

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
	_cannon2->_isControl = false;
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	if(_cannon2->_isDead())
	_cannon2->Update();

	for (auto bullet : _cannon1->GetBullets())
	{
		if (bullet->AttackCannon(_cannon2))
		{

		}
	}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}
