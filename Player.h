#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Player : public GameObject
{
	int hModel_;	//モデル番号
	Text* pText;

	XMVECTOR cameraDirction_;	//カメラ方向

	//削除予定の変数
	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;
	int s = 0;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	Player() {};

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

