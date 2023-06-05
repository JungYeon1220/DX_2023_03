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
    if (col->GetWorldPos().x < Right() && col->GetWorldPos().x > Left())
    {
        if (col->Bottom() < Top() && col->Top() > Bottom())
        {
            return true;
        }
    }

    if (col->GetWorldPos().y > Bottom() && col->GetWorldPos().y < Top())
    {
        if (col->Left() < Right() && col->Right() > Left())
        {
            return true;
        }
    }

    if (col->IsCollision(Vector2(Left(), Top()))
        || col->IsCollision(Vector2(Right(), Top()))
        || col->IsCollision(Vector2(Left(), Bottom()))
        || col->IsCollision(Vector2(Right(), Bottom())))
    {
        return true;
    }

    return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> col)
{
    if (Left() > col->Right() || Right() < col->Left()
        || Top() < col->Bottom() || Bottom() > col->Top())
        return false;

    return true;
}

void RectCollider::SetScale(Vector2 scale)
{
    _transform->SetScale(scale);
    _size.x *= scale.x;
    _size.y *= scale.y;
}

bool RectCollider::IsCollision(const Vector2& pos)
{
    if (pos.x > Left() && pos.x < Right())
    {
        if (pos.y > Bottom() && pos.y < Top())
            return true;
    }
    return false;
}
