#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#include "Engine/Camera.h"

const float SPEED = 0.1f;//移動速度


//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//初期化
void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Model/Character.fbx");
	assert(hModel_ >= 0);

	//transform_.rotate_.y = 450;

	//仮カメラセット
	camPosition_ = { 0.0f,3.0f,-5.0f };
	camTarget_ = { 0.0f,0.0f,1.0f };

	//カメラの方向ベクトルを取得
	SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);

}

//更新
void Player::Update()
{
	//移動処理
	CharacterMove(&transform_);

	//アイテムの処理
	ItemRelated();
	
	//仮カメラ
	{
		
		if (Input::IsKeyDown(DIK_SPACE)) {
			if (s > 4) { s = 0; }
			s++;
		}

		switch (s)
		{
		case 0:	//キャラクター背後
			camPosition_ = { 0.0f,3.0f,-5.0f };
			camTarget_ = { 0.0f,0.0f,1.0f };
			break;
		case 1:	//キャラクター正面
			camPosition_ = { 0.0f,3.0f,5.0f };
			camTarget_ = { 0.0f,0.0f,-1.0f };
			break;
		case 2:	//キャラクター右側
			camPosition_ = { 5.0f,3.0f,0.0f };
			camTarget_ = { -1.0f,0.0f,0.0f };
			break;
		case 3://キャラクター左側
			camPosition_ = { -5.0f,3.0f,0.0f };
			camTarget_ = { 1.0f,0.0f,0.0f };
			break;
		case 4://キャラクター右前斜め
			camPosition_ = { 5.0f,3.0f,-5.0f };
			camTarget_ = { -1.0f,0.0f,1.0f };
			break;
		case 5://キャラクター左奥斜め
			camPosition_ = { -5.0f,3.0f,5.0f };
			camTarget_ = { 1.0f,0.0f,-1.0f };
			break;
		}
		Camera::SetPosition(camPosition_);
		Camera::SetTarget(camTarget_);
	}

}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}

void Player::CharacterMove(Transform* _transform)
{
		//カメラ方向の変換
		if (IsChangeMoveDir()) {
			SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
		}

		//情報の初期化&代入
		XMVECTOR vPos = XMLoadFloat3(&_transform->position_);
		float angle = atan2(XMVectorGetX(cameraDirction_), XMVectorGetZ(cameraDirction_));

		//各入力時の処理
		EachInputProsess(vPos, angle);

		//モデルの向きを変更
		if(InputAnyWASD())
		transform_.rotate_.y = XMConvertToDegrees(angle);

		//結果を代入
		XMStoreFloat3(&_transform->position_, vPos);
}

void Player::EachInputProsess(XMVECTOR& _vec, float& _angle)
{
	//入力パターン一覧
	/*
	* W		{ angle = Degree 0
	* WA	{ angle = Degree 45
	* A		{ angle = Degree 90
	* AS	{ angle = Degree 135
	* S		{ angle = Degree 180
	* SD	{ angle = Degree 225
	* D		{ angel = Degree 270
	* DW	{ angle = Degree 315
	*
	* ※問題点
	* キーが２つ以上押された時に違う挙動に移らないようにするべき？
	* 対応策
	* キーが二つ以上押されていないかを確認する関数を用意
	* ？？？
	*/

	//向きを代入
	if (Input::IsKey(DIK_W)) {
		if (Input::IsKey(DIK_A))
			_angle -= XMConvertToRadians(45);
		else if (Input::IsKey(DIK_D))
			_angle -= XMConvertToRadians(315);
		else
			_angle -= XMConvertToRadians(0);
	}
	else if (Input::IsKey(DIK_A)) {
		if (Input::IsKey(DIK_S))
			_angle -= XMConvertToRadians(135);
		else
			_angle -= XMConvertToRadians(90);
	}
	else if (Input::IsKey(DIK_S)) {
		if (Input::IsKey(DIK_D))
			_angle -= XMConvertToRadians(225);
		else
			_angle -= XMConvertToRadians(180);
	}
	else if (Input::IsKey(DIK_D)) {
		_angle -= XMConvertToRadians(270);
	}

	//WASDいずれかのキーが押されたとき
	if (InputAnyWASD()) {
		XMVECTOR move = { 0,0,SPEED,0 };
		_vec += XMVector3TransformCoord(move, XMMatrixRotationY(_angle));
	}

}

bool Player::InputAnyWASD()
{
	if (Input::IsKey(DIK_W) ||
		Input::IsKey(DIK_A) ||
		Input::IsKey(DIK_S) ||
		Input::IsKey(DIK_D)) {
		return true;
	}
	return false;
}

XMVECTOR Player::GetCamDirVector(XMFLOAT3 _camPosition, XMFLOAT3 _camTarget)
{
#if 1
	//y座標を０で初期化
	_camPosition.y = 0.0f;
	_camTarget.y = 0.0f;

	//XMFLOAT3 → XMVECTORに変換
	XMVECTOR begin = XMLoadFloat3(&_camPosition);
	XMVECTOR end = XMLoadFloat3(&_camTarget);

	//方向ベクトルを取得
	XMVECTOR camDirection = XMVectorSubtract(end, begin);

	//長さを初期化
	camDirection = XMVector3Normalize(camDirection);

	//戻り値
	return camDirection;
#else

	_camPosition.y = 0.0f;
	_camTarget.y = 0.0f;

	return (XMVector3Normalize(XMVectorSubtract(XMLoadFloat3(&_camTarget), XMLoadFloat3(&_camPosition))));

#endif
}

bool Player::IsChangeMoveDir()
{
	bool isCamChanege = true;

	//カメラが切り替わったら
	if (isCamChanege) {
		//移動キーが入力されていなければ
		if (!Input::IsKey(DIK_W) &&
			!Input::IsKey(DIK_A) &&
			!Input::IsKey(DIK_S) &&
			!Input::IsKey(DIK_D)) {
			return true;
		}
	}

	return false;
}

void Player::ItemRelated()
{
	//アイテム取得処理
	Inventory::GetItem();
	//アイテム使用処理
	Inventory::UseItem();
	//アイテム放棄処理
	Inventory::DropItem();
}

void Inventory::GetItem()
{
}

void Inventory::UseItem()
{
}

void Inventory::DropItem()
{
}
