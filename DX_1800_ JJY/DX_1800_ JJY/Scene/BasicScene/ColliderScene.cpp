#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_circleColliderMouse = make_shared<CircleCollider>(100);
	_rectCollider = make_shared<RectCollider>(Vector2(100, 50));
	_rectColliderKeyboard = make_shared<RectCollider>(Vector2(100, 200));
	_circleCollider = make_shared<CircleCollider>(80);
	_rectCollider->GetTransform()->SetPosition(CENTER);
	_circleCollider->GetTransform()->SetPosition(CENTER);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_circleColliderMouse->GetTransform()->SetPosition(MOUSE_POS);

	if (KEY_PRESS('W'))
	{
		_rectColliderKeyboard->GetTransform()->AddVector2(Vector2(0.0f, 1.0f) * DELTA_TIME * 500.0f);
	}
	if (KEY_PRESS('S'))
	{
		_rectColliderKeyboard->GetTransform()->AddVector2(Vector2( 0.0f, -1.0f ) * DELTA_TIME * 500.0f);
	}
	if (KEY_PRESS('D'))
	{
		_rectColliderKeyboard->GetTransform()->AddVector2(Vector2( 1.0f, 0.0f ) * DELTA_TIME * 500.0f);
	}
	if (KEY_PRESS('A'))
	{
		_rectColliderKeyboard->GetTransform()->AddVector2(Vector2( -1.0f, 0.0f ) * DELTA_TIME * 500.0f);
	}

	_circleColliderMouse->Update();
	_circleCollider->Update();
	_rectCollider->Update();
	_rectColliderKeyboard->Update();

	_circleColliderMouse->Block(_circleCollider);
	_circleColliderMouse->Block(_rectCollider);
	_rectColliderKeyboard->Block(_circleCollider);
	_rectColliderKeyboard->Block(_rectCollider);


	if (_rectColliderKeyboard->IsCollision(_circleCollider))
	{
		_rectColliderKeyboard->SetRed();
		_circleCollider->SetRed();
	}
	else
	{
		_rectColliderKeyboard->SetGreen();
		_circleCollider->SetGreen();
	}
	//_rectColliderMouse->GetTransform()->SetPosition(_pos);
	_rectColliderKeyboard->GetTransform()->SetScale(_scale);
	_rectColliderKeyboard->GetTransform()->SetAngle(_angle);
}

void ColliderScene::Render()
{
	_circleColliderMouse->Render();
	_circleCollider->Render();
	_rectCollider->Render();
	_rectColliderKeyboard->Render();
}

void ColliderScene::PostRender()
{
	ImGui::SliderFloat2("Pos", (float*)&_pos, 0, WIN_WIDTH, "%.0f");
	ImGui::SliderFloat2("Scale", (float*)&_scale, 0, 3, "%.1f");
	ImGui::SliderFloat("Angle", &_angle, 0, 2 * PI, "%.1f");
}
