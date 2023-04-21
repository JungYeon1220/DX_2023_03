#include "framework.h"
#include "LIneScene.h"

LIneScene::LIneScene()
{
	_floorLine = make_shared<Line>(Vector2(100, 600), Vector2(1300, 300));
	_mouseLine = make_shared<Line>(Vector2(100, 300), Vector2(1000, 700));
	_shadowLine = make_shared<Line>(Vector2(100, 500), Vector2(110, 500));
}

LIneScene::~LIneScene()
{
}

void LIneScene::Update()
{
	_mouseLine->_endPos = mousePos;

	Vector2 mouseLineVector = _mouseLine->_endPos - _mouseLine->_startPos;
	Vector2 floorVector = _floorLine->_endPos - _floorLine->_startPos;
	Vector2 floorNormal = floorVector.NormalVector2();

	float length = mouseLineVector.Dot(floorNormal);

	_shadowLine->_endPos = floorNormal * length + _shadowLine->_startPos;

	//Vector2 unitVector = Vector2(_floorLine->_endPos - _floorLine->_startPos) / _floorLine->_startPos.Distance(_floorLine->_endPos);

	//Vector2 shadowStart = _floorLine->_startPos + ((_mouseLine->_startPos - _floorLine->_startPos) / 3.0f) + (unitVector * ((_mouseLine->_startPos - _floorLine->_startPos).Dot(unitVector) * 2.0f / 3.0f));

	//_shadowLine->_startPos = shadowStart;

	//float shadowLength = (_mouseLine->_endPos - _mouseLine->_startPos).Dot(unitVector);

	//_shadowLine->_endPos = _shadowLine->_startPos + (unitVector * shadowLength);
}

void LIneScene::Render(HDC hdc)
{
	_floorLine->Render(hdc);
	_shadowLine->Render(hdc);
	_mouseLine->Render(hdc);
}
