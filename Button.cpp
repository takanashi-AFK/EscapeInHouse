#include "Button.h"

    //�R���X�g���N�^
Button::Button() {
};

    //������
void Button::Initialize() {
    //�摜�̃��[�h
    hPict_ = Image::Load("Button.png");
    assert(hPict_ >= 0);

    SetRect(hPict_);
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
    void Button::SetRect(int _Picthandle) 
    {

    };

    //�{�^���͈͓̔��ɃJ�[�\�������邩�𔻒肷��
    bool Button::isButton(XMFLOAT3 Mpos) 
    {
        //�͈͓���
        return (Mpos.x > rect_.TL.x && Mpos.z < rect_.TL.z &&
            Mpos.x < rect_.TR.x && Mpos.z <rect_.TR.z &&
            Mpos.x > rect_.BL.x && Mpos.z > rect_.BL.z &&
            Mpos.x < rect_.BR.x && Mpos.z > rect_.BR.z);
    };