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
	_circleCollider->Update();
	_rectCollider->Update();
	_rectColliderMouse->Update();

	if (_rectCollider->IsOBB(_rectColliderMouse))
	{
		_rectCollider->SetRed();
	}
	else
	{
		_rectCollider->SetGreen();
	}
	_rectColliderMouse->GetTransform()->SetPosition(MOUSE_POS);
	_rectColliderMouse->GetTransform()->SetScale(_scale);
	_rectColliderMouse->GetTransform()->SetAngle(_angle);
}

void ColliderScene::Render()
{
	_circleCollider->Render();
	_rectCollider->Render();
	_rectColliderMouse->Render();
}

void ColliderScene::PostRender()
{
	ImGui::SliderFloat2("Pos", (float*)&_pos, 0, WIN_WIDTH, "%.0f");
	ImGui::SliderFloat2("Scale", (float*)&_scale, 0, 3, "%.1f");
	ImGui::SliderFloat2("Scale", (float*)&MOUSE_POS, 0, 3, "%.1f");
	ImGui::SliderFloat("Angle", &_angle, 0, 2 * PI, "%.1f");
}
