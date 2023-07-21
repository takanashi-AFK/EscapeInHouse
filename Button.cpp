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
        //rect_.TL = { ( - width / 2 + transform_.position_.x)/800,(height / 2 + transform_.position_.y)/600 ,0};
        //rect_.TR = { (width / 2 + transform_.position_.x) / 800,(height / 2 + transform_.position_.y) / 600,0 };
        //rect_.BL = { ( - width / 2 + transform_.position_.x) / 800,( - height / 2 + transform_.position_.y) / 600,0};
        //rect_.BR = { (width / 2 + transform_.position_.x) / 800,( - height / 2 + transform_.position_.y) / 600,0};
        rect_.TL = { (-width / 2 + transform_.position_.x) /1200 ,(height / 2 + transform_.position_.y)  /720 ,0 };
        rect_.TR = { (width / 2 + transform_.position_.x)  /1200 ,(height / 2 + transform_.position_.y)  /720 ,0 };
        rect_.BL = { (-width / 2 + transform_.position_.x) /1200 ,(-height / 2 + transform_.position_.y) /720 ,0 };
        rect_.BR = { (width / 2 + transform_.position_.x)  /1200 ,(-height / 2 + transform_.position_.y) /720 ,0 };

    };

    //�{�^���͈͓̔��ɃJ�[�\�������邩�𔻒肷��
    bool Button::IsButton(XMFLOAT3 Mpos) 
    {
        if (Mpos.x >= rect_.TL.x && Mpos.y <= rect_.TL.y &&
            Mpos.x <= rect_.TR.x && Mpos.y <rect_.TR.y &&
            Mpos.x >= rect_.BL.x && Mpos.y > rect_.BL.y &&
            Mpos.x <= rect_.BR.x && Mpos.y > rect_.BR.y)
            return (true);

        //�͈͓�����Ȃ�
        else
            return(false);
       
            
    };
    