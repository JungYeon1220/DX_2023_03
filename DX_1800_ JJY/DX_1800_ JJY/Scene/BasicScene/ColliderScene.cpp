#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rectCollider = make_shared<RectCollider>(Vector2(100, 50));
	_rectColliderMouse = make_shared<RectCollider>(Vector2(100, 200));
	_circleCollider = make_shared<CircleCollider>(80);
	_rectCollider->GetTransform()->SetPosition(CENTER);
	_circleCollider->GetTransform()->SetPosition(CENTER);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rectColliderMouse->GetTransform()->SetPosition(MOUSE_POS);

	if (_rectCollider->IsCollision(_rectColliderMouse))
	{
		_rectCollider->SetRed();
	}
	else
	{
		_rectCollider->SetGreen();
	}

	_circleCollider->Update();
	_rectCollider->Update();
	_rectColliderMouse->Update();
}

void ColliderScene::Render()
{
	_circleCollider->Render();
	_rectCollider->Render();
	_rectColliderMouse->Render();
}
