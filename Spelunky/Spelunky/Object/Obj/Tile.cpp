#include "framework.h"
#include "Tile.h"

Tile::Tile()
{
	_transform = make_shared<Transform>();
	_sprite = make_shared<Sprite_Frame>(L"Resource/Texture/floor_cave.png", Vector2(12, 12), Vector2(100.0f, 100.0f));
	_col = make_shared<RectCollider>(_sprite->GetClipsize());
	_transform->SetParent(_col->GetTransform());

	CreateClips();
}

Tile::~Tile()
{
}

void Tile::SetType(Tile::Type value)
{
	_type = value;
}

bool Tile::Block(shared_ptr<Collider> col)
{
	if (_type != Tile::Type::NORMAL)
		return false;
	Vector2 colPos = col->GetWorldPos();
	Vector2 pos = _col->GetWorldPos();
	Vector2 halfSize = _sprite->GetClipsize() * 0.5f;
	if ((colPos.x < pos.x + halfSize.x && colPos.x > pos.x - halfSize.x)
	|| (colPos.y < pos.y + halfSize.y && colPos.y > pos.y - halfSize.y))
	{
		return _col->Block(col);
	}

	return false;
}

void Tile::Update()
{
	_col->GetTransform()->SetPosition(_pos);
	_transform->Update();
	_sprite->SetCurClip(_clips[_type]);
	_sprite->Update();
	_col->Update();
}

void Tile::Render()
{
	_transform->SetWorldBuffer(0);
	_sprite->Render();
	_col->Render();
}

void Tile::CreateClips()
{
	shared_ptr<SRV> srv = ADD_SRV(L"Resource/Texture/floor_cave.png");
	Vector2 imageSize = srv->GetImageSize();
	Vector2 maxFrame = Vector2(12, 12);
	Vector2 size;
	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;

	Vector2 startPos = Vector2((11.0f * imageSize.x) / maxFrame.x, imageSize.y * 11.0f / maxFrame.y);
	Action::Clip clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
	_clips.push_back(clip);
	
	startPos = Vector2((0.0f * imageSize.x) / maxFrame.x, imageSize.y * 0.0f / maxFrame.y);
	clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
	_clips.push_back(clip);

	startPos = Vector2((4.0f * imageSize.x) / maxFrame.x, imageSize.y * 0.0f / maxFrame.y);
	clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
	_clips.push_back(clip);
}
