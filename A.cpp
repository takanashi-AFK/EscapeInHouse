#include "A.h"
#include "Engine/Model.h"

A::A(GameObject* parent)
	: GameObject(parent, "A"),hModel_(-1)
{
}

void A::Initialize()
{
	hModel_ = Model::Load("AModel.fbx");
	assert(hModel_ >= 0);
}

void A::Update()
{
}

void A::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void A::Release()
{
}
