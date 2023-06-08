#include "Stage.h"
#include "Engine/Model.h"

Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage"), hModel_(-1)
{
}

void Stage::Initialize()
{
	hModel_ = Model::Load("YellowFloor.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 0,0,0 };
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Stage::Release()
{
}

Rect4 Stage::GetRect(XMFLOAT3 _center, float _widthSide, float _heightSide)
{
	_widthSide = _widthSide / 2;
	_heightSide = _heightSide / 2;
	Rect4 ret;
	//ç∂è„
	ret.TL = { _center.x - (_widthSide / 2) ,_center.y + (_heightSide / 2),0 };
	//âEè„
	ret.TR = { _center.x + (_widthSide / 2),_center.y + (_heightSide / 2),0 };
	//ç∂â∫
	ret.BL = { _center.x - (_widthSide / 2),_center.y - (_heightSide / 2),0 };
	//âEâ∫
	ret.BR = { _center.x + (_widthSide / 2),_center.y - (_heightSide / 2),0 };
	return(ret);
}