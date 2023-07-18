#include "Button.h"

    //コンストラクタ
Button::Button() {
};

    //初期化
void Button::Initialize() {
    //画像のロード
    hPict_ = Image::Load("Button.png");
    assert(hPict_ >= 0);

    SetRect(hPict_);
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
    void Button::SetRect(int _Picthandle) {
    
    };

    //ボタンの範囲内にカーソルかあるかを判定する
    bool Button::isButton(XMFLOAT3 Mpos) {

        //範囲内か
        return (Mpos.x > _r.TL.x && Mpos.z < _r.TL.z &&
            Mpos.x < _r.TR.x && Mpos.z <_r.TR.z &&
            Mpos.x > _r.BL.x && Mpos.z > _r.BL.z &&
            Mpos.x < _r.BR.x && Mpos.z > _r.BR.z);
    };