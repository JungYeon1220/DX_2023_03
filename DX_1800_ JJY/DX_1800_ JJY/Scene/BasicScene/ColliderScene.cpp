#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rectCollider = make_shared<RectCollider>(Vector2(100.0f, 80.0f));
	_rectCollider2 = make_shared<RectCollider>(Vector2(120.0f, 120.0f));
	_circleCollider = make_shared<CircleCollider>(50.0f);
	_circleCollider2 = make_shared<CircleCollider>(70.0f);

	_colliders.push_back(_rectCollider);
	_colliders.push_back(_rectCollider2);
	_colliders.push_back(_circleCollider);
	_colliders.push_back(_circleCollider2);

	_circleCollider2->GetTransform()->SetPosition(CENTER + Vector2(-200.0f, 0.0f));
	_rectCollider2->GetTransform()->SetPosition(CENTER + Vector2(200.0f, 0.0f));
	_rectCollider->GetTransform()->SetPosition(Vector2(-500.0f, -500.0f));
	_circleCollider->GetTransform()->SetPosition(Vector2(-500.0f, -500.0f));
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	if (KEY_PRESS('A'))
		_circleCollider->GetTransform()->SetPosition(MOUSE_POS);
	else
		_circleCollider->GetTransform()->SetPosition(Vector2(-500.0f, -500.0f));

	if(KEY_PRESS('D'))
		_rectCollider->GetTransform()->SetPosition(MOUSE_POS);
	else
		_rectCollider->GetTransform()->SetPosition(Vector2(-500.0f, -500.0f));

	for (int i = 0; i < _colliders.size(); i++)
	{
		bool isCollision = false;
		for (int j = 0; j < _colliders.size(); j++)
		{
			if (i == j)
				continue;

			if (_colliders[i]->IsCollision(_colliders[j]))
				isCollision = true;
		}

		if (isCollision)
			_colliders[i]->SetColorRed();
		else
			_colliders[i]->SetColorGreen();
	}

	for (auto col : _colliders)
		col->Update();
}

void ColliderScene::Render()
{
	for (auto col : _colliders)
		col->Render();
}
