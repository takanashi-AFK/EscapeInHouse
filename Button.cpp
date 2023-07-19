#include "Button.h"

    //�R���X�g���N�^
Button::Button(GameObject* parent) 
    : GameObject(parent, "Button") {
};

    //������
void Button::Initialize() {
    //�摜�̃��[�h
    hPict_ = Image::Load("ButtonA_1.png");
    assert(hPict_ >= 0);

    width = Image::GetWidth();
    height = Image::GetHeight();

    SetRect();
};

    //�X�V
    void Button::Update() {
    };

    //�`��
    void Button::Draw() {
        Image::SetTransform(hPict_, transform_);
        Image::Draw(hPict_);
    };

    //�J��
    void Button::Release() {
    };

    //�ǂݍ��܂ꂽ�摜����e���_���擾����
    void Button::SetRect(/*int _Picthandle*/) 
    {
        rect_.TL = { ( - width / 2 + transform_.position_.x)/800,(height / 2 + transform_.position_.y)/600 ,0};
        rect_.TR = { (width / 2 + transform_.position_.x) / 800,(height / 2 + transform_.position_.y) / 600,0 };
        rect_.BL = { ( - width / 2 + transform_.position_.x) / 800,( - height / 2 + transform_.position_.y) / 600,0};
        rect_.BR = { (width / 2 + transform_.position_.x) / 800,( - height / 2 + transform_.position_.y) / 600,0};

    };

    //�{�^���͈͓̔��ɃJ�[�\�������邩�𔻒肷��
    bool Button::IsButton(XMFLOAT3 Mpos) 
    {
        //�͈͓���
        return (Mpos.x > rect_.TL.x && Mpos.z < rect_.TL.z &&
            Mpos.x < rect_.TR.x && Mpos.z <rect_.TR.z &&
            Mpos.x > rect_.BL.x && Mpos.z > rect_.BL.z &&
            Mpos.x < rect_.BR.x && Mpos.z > rect_.BR.z);
    };
    