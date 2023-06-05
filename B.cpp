#include "B.h"
#include "Engine/Model.h"

B::B(GameObject* parent)
	: GameObject(parent, "B"), hModel_(-1)
{
}

void B::Initialize()
{
	hModel_ = Model::Load("BModel.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = { 2,0,0 };
}

void B::Update()
{
}

void B::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void B::Release()
{
}
