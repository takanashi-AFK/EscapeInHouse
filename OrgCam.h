#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"

//テストシーンを管理するクラス
struct CAMERA_DATA {
	XMFLOAT3 camPos_;//位置 
	XMFLOAT3 camTarget_; // ちゅうしてん
	Rect4 camArea_;
	int camNumber;
};
class OrgCam : public GameObject
{
private:


public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	OrgCam(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};