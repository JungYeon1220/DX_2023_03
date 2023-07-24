#include "framework.h"
#include "Tile.h"

Tile::Tile()
{
	_transform = make_shared<Transform>();
	_floorSprite = make_shared<Sprite_Frame>(L"Resource/Texture/floor_cave.png", Vector2(12, 12), Vector2(100.0f, 100.0f));
	_miscSprite = make_shared<Sprite_Frame>(L"Resource/Texture/floormisc.png", Vector2(8, 8), Vector2(100.0f, 100.0f));
	_borderSprite = make_shared<Sprite_Frame>(L"Resource/Texture/border_main.png", Vector2(8, 8), Vector2(100.0f, 100.0f));
	_sprite = _floorSprite;

	_col = make_shared<RectCollider>(Vector2(100.0f, 100.0f));
	_transform->SetParent(_col->GetTransform());

	CreateClips();
}

Tile::~Tile()
{
}

void Tile::SetType(Tile::Type value)
{
	_type = value;

	if (value >= Tile::Type::UNBREAKABLE)
		_sprite = _borderSprite;
	else if (value >= Tile::Type::ONE_WAY && value < Tile::Type::UNBREAKABLE)
		_sprite = _miscSprite;
	else
		_sprite = _floorSprite;
}

bool Tile::Block(shared_ptr<Collider> col)
{
	if (_type == Tile::Type::EMPTY)
		return false;

	Vector2 colPos = col->GetWorldPos();
	Vector2 pos = _col->GetWorldPos();
	Vector2 halfSize = _sprite->GetClipsize() * 0.5f;

	if (_type == Tile::Type::NORMAL || _type == Tile::Type::UNBREAKABLE)
	{
		if ((colPos.x < pos.x + halfSize.x && colPos.x > pos.x - halfSize.x)
			|| (colPos.y < pos.y + halfSize.y && colPos.y > pos.y - halfSize.y))
		{
			return _col->Block(col);
		}
	}
	if (_type == Tile::Type::ONE_WAY)
	{
		if (_isActive == false)
			return false;

		if ((colPos.x < pos.x + halfSize.x && colPos.x > pos.x - halfSize.x)
			&& (colPos.y > pos.y + halfSize.y))
		{
			return _col->Block(col);
		}
	}

	return false;
}

void Tile::Update()
{
	if (_type == Tile::Type::EMPTY)
		return;
	_col->GetTransform()->SetPosition(_pos);
	_transform->Update();
	_sprite->SetCurClip(Vector2(0,0));
	_sprite->Update();
	_col->Update();
}

void Tile::Render()
{
	if (_type == Tile::Type::EMPTY)
		return;

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

	srv = ADD_SRV(L"Resource/Texture/floormisc.png");
	imageSize = srv->GetImageSize();
	maxFrame = Vector2(8, 8);
	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;

	startPos = Vector2((1.0f * imageSize.x) / maxFrame.x, imageSize.y * 1.0f / maxFrame.y);
	clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
	_clips.push_back(clip);

	srv = ADD_SRV(L"Resource/Texture/border_main.png");
	imageSize = srv->GetImageSize();
	maxFrame = Vector2(8, 8);
	size.x = imageSize.x / maxFrame.x;
	size.y = imageSize.y / maxFrame.y;

	startPos = Vector2((0.0f * imageSize.x) / maxFrame.x, imageSize.y * 1.0f / maxFrame.y);
	clip = Action::Clip(startPos.x, startPos.y, size.x, size.y, srv);
	_clips.push_back(clip);
}
