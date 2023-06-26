#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;

Camera::Camera()
{
	_view = make_shared<Transform>();
	_projection = make_shared<MatrixBuffer>();

	XMMATRIX projMatrix = XMMatrixOrthographicOffCenterLH(0, WIN_WIDTH, 0, WIN_HEIGHT, 0.0f, 1.0f);
	_projection->SetData(projMatrix);
	_projection->Update_Resource();
}

Camera::~Camera()
{
}

void Camera::Update()
{
	FreeMode();
	Shake();
	_view->Update();
}

void Camera::PostRender()
{
	if (ImGui::Button("Shake", { 50, 50 }))
	{
		ShakeStart(5.0f, 2.0f);
	}

	ImGui::Text("mousePos : { %.0f, %.0f }", GetWorldMousePos().x, GetWorldMousePos().y);
}

void Camera::ShakeStart(float magnitude, float duration, float reduceDamping)
{
	_magnitude = magnitude;
	_duration = duration;
	_reduceDamping = reduceDamping;

	_originPos = _view->GetWorldPos();
}

void Camera::SetViewPort(UINT width, UINT height)
{
}

void Camera::SetViewBuffer()
{
	_view->SetWorldBuffer(1);
}

void Camera::SetProjectionBuffer()
{
	_projection->SetVS_Buffer(2);
}

void Camera::SetPosition(Vector2 pos)
{
	_view->SetPosition(-pos);
}

void Camera::SetScale(Vector2 scale)
{
	_view->SetScale(scale);
}

void Camera::SetAngle(float angle)
{
	_view->SetAngle(-angle);
}

void Camera::AddVector2(Vector2 pos)
{
	_view->AddVector2(-pos);
}

void Camera::AddScale(Vector2 scale)
{
	_view->AddScale(scale);
}

void Camera::AddAngle(float angle)
{
	_view->AddAngle(-angle);
}

Vector2 Camera::GetWorldMousePos()
{
	XMMATRIX inverseMatrix = DirectX::XMMatrixInverse(nullptr, _view->GetSRT());

	Vector2 mousePos = MOUSE_POS;
	return mousePos.TransformCoord(inverseMatrix);
}

void Camera::Shake()
{
	if (_duration <= 0.0f)
		return;

	_duration -= DELTA_TIME;
	_magnitude -= _reduceDamping * DELTA_TIME;

	if (_magnitude <= 0.0f)
	{
		_magnitude = 0.0f;
		_duration = 0.0f;
	}

	Vector2 randomPos;
	randomPos.x = _originPos.x + MathUtility::RandomFloat(-_magnitude, _magnitude);
	randomPos.y = _originPos.y + MathUtility::RandomFloat(-_magnitude, _magnitude);
	SetPosition(randomPos);

	if (_duration <= 0.0f)
	{
		_magnitude = 0.0f;
		SetPosition(_originPos);
	}
}

void Camera::FreeMode()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('W'))
		{
			AddVector2(UP_VECTOR * _speed * DELTA_TIME);
		}
		if (KEY_PRESS('S'))
		{
			AddVector2(-UP_VECTOR * _speed * DELTA_TIME);
		}
		if (KEY_PRESS('D'))
		{
			AddVector2(RIGHT_VECTOR * _speed * DELTA_TIME);
		}
		if (KEY_PRESS('A'))
		{
			AddVector2(-RIGHT_VECTOR * _speed * DELTA_TIME);
		}
	}
}

void Camera::FollowMode()
{
}
