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
    void Button::SetRect(int _Picthandle) {
    
    };

    //�{�^���͈͓̔��ɃJ�[�\�������邩�𔻒肷��
    bool Button::isButton(XMFLOAT3 Mpos) {

        //�͈͓���
        return (Mpos.x > _r.TL.x && Mpos.z < _r.TL.z &&
            Mpos.x < _r.TR.x && Mpos.z <_r.TR.z &&
            Mpos.x > _r.BL.x && Mpos.z > _r.BL.z &&
            Mpos.x < _r.BR.x && Mpos.z > _r.BR.z);
    };