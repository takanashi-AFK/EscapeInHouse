#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/Transform.h"


//４点を格納する構造体
struct Rect4
{
    XMFLOAT3 TL, TR, BL, BR;
};

class Button
    :public GameObject
{
private:
    int hPict_;  //画像handle
    Rect4 rect_; //画像の頂点４つを入れる
    float width;
    float height;

    
public:
    //コンストラクタ
    Button(GameObject* parent);

    //初期化
    void Initialize();

    //更新
    void Update();

    // 描画
    void Draw();

    //開放
    void Release();

    //読み込まれた画像から各頂点を取得する
    void SetRect(/*int _Picthandle*/);

    //ボタンの範囲内にカーソルかあるかを判定する
    bool IsButton(XMFLOAT3 Mpos);
};