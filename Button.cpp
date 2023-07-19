#include "Button.h"

    //コンストラクタ
Button::Button(GameObject* parent) 
    : GameObject(parent, "Button") {
};

    //初期化
void Button::Initialize() {
    //画像のロード
    hPict_ = Image::Load("ButtonA_1.png");
    assert(hPict_ >= 0);

    width = Image::GetWidth();
    height = Image::GetHeight();

    SetRect();
};

    //更新
    void Button::Update() {
    };

    //描画
    void Button::Draw() {
        Image::SetTransform(hPict_, transform_);
        Image::Draw(hPict_);
    };

    //開放
    void Button::Release() {
    };

    //読み込まれた画像から各頂点を取得する
    void Button::SetRect(/*int _Picthandle*/) 
    {
        rect_.TL = { ( - width / 2 + transform_.position_.x)/800,(height / 2 + transform_.position_.y)/600 ,0};
        rect_.TR = { (width / 2 + transform_.position_.x) / 800,(height / 2 + transform_.position_.y) / 600,0 };
        rect_.BL = { ( - width / 2 + transform_.position_.x) / 800,( - height / 2 + transform_.position_.y) / 600,0};
        rect_.BR = { (width / 2 + transform_.position_.x) / 800,( - height / 2 + transform_.position_.y) / 600,0};

    };

    //ボタンの範囲内にカーソルかあるかを判定する
    bool Button::IsButton(XMFLOAT3 Mpos) 
    {
        //範囲内か
        return (Mpos.x > rect_.TL.x && Mpos.z < rect_.TL.z &&
            Mpos.x < rect_.TR.x && Mpos.z <rect_.TR.z &&
            Mpos.x > rect_.BL.x && Mpos.z > rect_.BL.z &&
            Mpos.x < rect_.BR.x && Mpos.z > rect_.BR.z);
    };
    