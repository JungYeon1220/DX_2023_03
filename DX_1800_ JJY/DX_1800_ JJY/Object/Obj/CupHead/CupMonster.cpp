#include "framework.h"
#include "CupMonster.h"

CupMonster::CupMonster()
{
	_col = make_shared<CircleCollider>(100.0f);
	_transform = make_shared<Transform>();

	_transform->SetParent(_col->GetTransform());
	_col->GetTransform()->SetPosition(Vector2(1000.0f, 300.0f));
}

CupMonster::~CupMonster()
{
}

void CupMonster::Update()
{
	_transform->Update();
	_col->Update();
}

void CupMonster::Render()
{
	_transform->SetWorldBuffer(0);
	_col->Render();
}

void CupMonster::CreateAction(string name, float speed, Action::Type type, CallBack callBack)
{

}
