#pragma once
#include "Engine/GameObject.h"

namespace Inventory
{
	/// <summary>
	/// アイテムを取得する処理
	/// </summary>
	void GetItem();

	/// <summary>
	/// アイテムを使用する処理
	/// </summary>
	void UseItem();

	/// <summary>
	/// アイテムを放棄する処理
	/// </summary>
	void DropItem();
}


class Player : public GameObject
{
	int hModel_;	//モデル番号

	XMVECTOR cameraDirction_;	//カメラ方向

	//削除予定の変数
	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;
	int s = 0;

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
	/// プレイヤーの移動方向ベクトルを設定する
	/// </summary>
	/// <param name="_dir">カメラの方向ベクトル</param>
	void SetMoveDirction(XMVECTOR _dir) { this->cameraDirction_ = _dir; }

	/// <summary>
	/// 操作キャラクターの移動処理
	/// </summary>
	/// <param name="_transform">位置、向き、拡大率などの情報</param>
	void CharacterMove(Transform* _transform);

	/// <summary>
	/// 各キーの入力時に行われる処理
	/// </summary>
	/// <param name="_vec">キャラクターの位置ベクトル</param>
	/// <param name="_angle">キャラクターの進行方向</param>
	void EachInputProsess(XMVECTOR& _vec,float& _angle);

	/// <summary>
	/// WASDのいずれかのキーが入力されたか
	/// </summary>
	/// <returns>入力されていればtrue</returns>
	bool InputAnyWASD();

	/// <summary>
	/// カメラの方向ベクトルを取得
	/// </summary>
	/// <param name="_camPosition">カメラの位置</param>
	/// <param name="_camTarget">カメラの焦点</param>
	/// <returns>カメラの方向ベクトル</returns>
	XMVECTOR GetCamDirVector(XMFLOAT3 _camPosition, XMFLOAT3 _camTarget);

	/// <summary>
	/// 移動方向を変更して良いか
	/// </summary>
	/// <returns>変更して良ければtrue</returns>
	bool IsChangeMoveDir();

	/// <summary>
	/// アイテム関連全般の処理
	/// </summary>
	void ItemRelated();

	

	//必要な機能・行動
	/*
	*	歩く
	*	アイテムをしまう
	*	アイテムを拾う
	*	アイテムを使う
	*	アイテムを捨てる
	*/

};

