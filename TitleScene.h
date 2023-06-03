#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//テストシーンを管理するクラス
class TitleScene : public GameObject
{
	
	XMFLOAT3 mousePos;		//この変数にマウスの座標を代入します。
	bool is_same_position;	//同じ座標にいるときに発動します
	Text* pText;			//マウスの位置を"試験的"に表示させています。

	enum STATES{				//出現させる絵を変えるために使用します
		APict = 0,
		BPict,

		MAX
	};
	int hPict_[STATES::MAX];
	int state_;			//ステータスを変化させるときに使用します

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};