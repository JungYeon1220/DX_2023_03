#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 size)
: _size(size)
{
	CreateVertices();
	CreateData();

    _type = Type::RECT;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
    _transform->Update();

    _colorBuffer->SetColor(_color);
    _colorBuffer->Update_Resource();
}

void RectCollider::Render()
{
    _transform->SetWorldBuffer(0);
    _colorBuffer->SetPS_Buffer(0);

    _vertexBuffer->SetIA_VertexBuffer();
    _vs->SetIA_InputLayOut();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set_VS();
    _ps->Set_PS();

    DC->Draw(_vertices.size(),0);
}

void RectCollider::CreateVertices()
{
    Vertex v;

    Vector2 halfSize = _size * 0.5f;

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
    _vertices.push_back(v);

    v.pos = { halfSize.x, halfSize.y, 0.0f }; // 오른쪽 위
    _vertices.push_back(v);

    v.pos = { halfSize.x, -halfSize.y, 0.0f }; // 오른쪽 아래
    _vertices.push_back(v);

    v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // 왼쪽 아래
    _vertices.push_back(v);

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
    _vertices.push_back(v);
}

void RectCollider::CreateData()
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _colorBuffer = make_shared<ColorBuffer>();

    _vs = make_shared<VertexShader>(L"Shader/ColliderVS.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColliderPS.hlsl");
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> col)
{
    AABB_Info info = GetAABB_Info();

    Vector2 circleWorldPos = col->GetWorldPos();

    float left = col->GetWorldPos().x - col->GetWorldRadius();
    float right = col->GetWorldPos().x + col->GetWorldRadius();
    float top = col->GetWorldPos().y + col->GetWorldRadius();
    float bottom = col->GetWorldPos().y - col->GetWorldRadius();

    if (circleWorldPos.x < info.right && circleWorldPos.x > info.left)
    {
        if (bottom < info.top && top > info.bottom)
        {
            return true;
        }
    }

    if (circleWorldPos.y > info.bottom && circleWorldPos.y < info.top)
    {
        if (left < info.right && right > info.left)
        {
            return true;
        }
    }

    if (col->IsCollision(Vector2(info.left, info.top))
        || col->IsCollision(Vector2(info.right, info.top))
        || col->IsCollision(Vector2(info.left, info.bottom))
        || col->IsCollision(Vector2(info.right, info.bottom)))
    {
        return true;
    }

    return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> col)
{
    AABB_Info aInfo = GetAABB_Info();
    AABB_Info bInfo = col->GetAABB_Info();

    if (aInfo.left > bInfo.right || aInfo.right < bInfo.left
        || aInfo.top < bInfo.bottom || aInfo.bottom > bInfo.top)
        return false;

    return true;
}

RectCollider::AABB_Info RectCollider::GetAABB_Info()
{
    AABB_Info info;
    info.left = _transform->GetWorldPos().x - _size.x * _transform->GetWorldScale().x * 0.5f;
    info.right = _transform->GetWorldPos().x + _size.x * _transform->GetWorldScale().x * 0.5f;
    info.top = _transform->GetWorldPos().y + _size.y * _transform->GetWorldScale().y * 0.5f;
    info.bottom = _transform->GetWorldPos().y - _size.y * _transform->GetWorldScale().y * 0.5f;

    return info;
}

RectCollider::OBB_Info RectCollider::GetOBB_Info()
{
    OBB_Info info;
    info.pos = _transform->GetWorldPos();

    XMFLOAT4X4 matrix;
    XMStoreFloat4x4(&matrix, _transform->GetSRT());

    return OBB_Info();
}

bool RectCollider::IsCollision(const Vector2& pos)
{
    AABB_Info info = GetAABB_Info();

    if (pos.x > info.left && pos.x < info.right)
    {
        if (pos.y > info.bottom && pos.y < info.top)
            return true;
    }
    return false;
}
