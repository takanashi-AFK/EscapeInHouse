#include "Stage.h"
#include "Engine/Model.h"
#include "Player.h"

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
	//¶ã
	ret.TL = { _center.x - (_widthSide / 2) ,_center.z + (_heightSide / 2),0 };
	//‰Eã
	ret.TR = { _center.x + (_widthSide / 2),_center.z + (_heightSide / 2),0 };
	//¶‰º
	ret.BL = { _center.x - (_widthSide / 2),_center.z - (_heightSide / 2),0 };
	//‰E‰º
	ret.BR = { _center.x + (_widthSide / 2),_center.z- (_heightSide / 2),0 };
	return(ret);
}

bool Stage::IsInRect(Rect4 _r)
{
	XMFLOAT3 playerPos;
	Player* p = new Player;
	playerPos = p->GetPosition();

	if (playerPos.x > _r.TL.x && playerPos.z < _r.TL.z &&
		playerPos.x < _r.TR.x && playerPos.z <_r.TR.z &&
		playerPos.x > _r.BL.x && playerPos.z > _r.BL.z &&
		playerPos.x < _r.BR.x && playerPos.z > _r.BR.z  ) {
		delete p;
		return true;
	}
	delete p;
	return false;
}
