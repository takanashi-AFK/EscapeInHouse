#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
	int hModel_;

	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// 2点を結ぶベクトルを求めて値を返す
	/// </summary>
	/// <param name="_vecA">始点</param>
	/// <param name="_vecB">終点</param>
	/// <returns>ベクトルAB</returns>
	XMVECTOR CalucurateVector(XMVECTOR _vecA, XMVECTOR _vecB);

	/// <summary>
	/// 2点を結ぶベクトルを求めて値を返す
	/// </summary>
	/// <param name="_posA">始点</param>
	/// <param name="_posB">終点</param>
	/// <returns>ベクトルAB</returns>
	XMVECTOR CalucurateVector(XMFLOAT3 _posA, XMFLOAT3 _posB);
};

