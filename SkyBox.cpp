#include "SkyBox.h"
#include "Engine/Model.h"

SkyBox& SkyBox::getInstance()
{
    if (instance == nullptr) {
        //instance = Instantiate<SkyBox>(nullptr);
    }
    return *instance;
}

void SkyBox::Initialize()
{
    hModel_ = Model::Load("");
    assert(hModel_ >= 0);
}

void SkyBox::Update()
{
}

void SkyBox::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void SkyBox::Release()
{
}
