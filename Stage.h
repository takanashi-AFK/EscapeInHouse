#pragma once
#include "Engine/GameObject.h"

struct Rect4
{
	XMFLOAT3 TL, TR, BL, BR;
};

class Stage : public GameObject
{
private:
	int hModel_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// モデルの4角を取得する関数
	/// </summary>
	/// <param name="_center">モデルの中央座標。GetPosition()</param>
	/// <param name="_widthSide">モデルの横の辺の長さ(x)</param>
	/// <param name="_heightSide">モデルの縦の辺の長さ(z)</param>
	/// <returns></returns>
	Rect4 GetRect(XMFLOAT3 _center, float _widthSide, float _heightSide);

};

