#include "framework.h"
#include "Tile.h"

Tile::Tile()
{
	_transform = make_shared<Transform>();
	_sprite = make_shared<Sprite_Frame>(L"Resource/Texture/floor_cave.png", Vector2(12, 12));


}

Tile::~Tile()
{
}

void Tile::Update()
{
}

void Tile::Render()
{
}
