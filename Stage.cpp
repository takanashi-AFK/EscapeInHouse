#include "Stage.h"
#include "Engine/Model.h"
#include "Player.h"

Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage"), hModel_(-1)
{
}

void Stage::Initialize()
{
	hModel_ = Model::Load("Stage/LDKandJapanese.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 0,0,0 };
	transform_.rotate_.y = 180;
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
	Rect4 ret;
	//¶ã
	ret.TL = { _center.x - (_widthSide / 2) ,0,_center.z + (_heightSide / 2) };
	//‰Eã
	ret.TR = { _center.x + (_widthSide / 2),0,_center.z + (_heightSide / 2)};
	//¶‰º
	ret.BL = { _center.x - (_widthSide / 2),0,_center.z - (_heightSide / 2) };
	//‰E‰º
	ret.BR = { _center.x + (_widthSide / 2),0,_center.z- (_heightSide / 2) };
	return(ret);
}

bool Stage::IsInRect(XMFLOAT3 _pos,Rect4 _r)
{
	if (_pos.x > _r.TL.x && _pos.z < _r.TL.z &&
		_pos.x < _r.TR.x && _pos.z <_r.TR.z &&
		_pos.x > _r.BL.x && _pos.z > _r.BL.z &&
		_pos.x < _r.BR.x && _pos.z > _r.BR.z  ) {
		return true;
	}
	return false;
}
