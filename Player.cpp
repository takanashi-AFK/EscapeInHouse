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

	dot = 0.0f;
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
		//移動方向の変換
		if (IsChangeMoveDir()) {
			SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
		}

		//情報の初期化&代入
		//XMVECTOR vDirZ = { 0,0,1,0 };
		//XMVECTOR vDirX = { 1,0,0,0 };
		//XMVECTOR vMoveZ = moveDirction_;
		XMVECTOR vPos = XMLoadFloat3(&_transform->position_);
		XMVECTOR vMoveX = XMVector3TransformCoord(moveDirction_, XMMatrixRotationY(XMConvertToRadians(90)));

		float angle = atan2(XMVectorGetX(moveDirction_), XMVectorGetZ(moveDirction_));

		if (Input::IsKey(DIK_A)) {
			angle -= XMConvertToRadians(90);
			XMVECTOR move = { 0,0,SPEED,0 };
			vPos += XMVector3TransformCoord(move,XMMatrixRotationY(angle));
		}

		if (Input::IsKey(DIK_D)) {
			angle -= XMConvertToRadians(270);
			XMVECTOR move = { 0,0,SPEED,0 };
			vPos += XMVector3TransformCoord(move, XMMatrixRotationY(angle));
		}

		if (Input::IsKey(DIK_W)) {
			angle -= XMConvertToRadians(0);
			XMVECTOR move = { 0,0,SPEED,0 };
			vPos += XMVector3TransformCoord(move, XMMatrixRotationY(angle));
		}

		if (Input::IsKey(DIK_S)) {
			angle -= XMConvertToRadians(180);
			XMVECTOR move = { 0,0,SPEED,0 };
			vPos += XMVector3TransformCoord(move, XMMatrixRotationY(angle));
		}

		float speed = SPEED;
		
		////動作実行
		//if (Input::IsKey(DIK_W)) { 
		//	vPos += XMVectorScale(vMoveZ, speed);
		//}

		/*if (Input::IsKey(DIK_A)) { 
			vPos -= XMVectorScale(vMoveX, speed); 
		}*/
		
		/*if (Input::IsKey(DIK_S)) { 
			vPos -= XMVectorScale(vMoveZ, speed);
		}*/
		
		/*if (Input::IsKey(DIK_D)) { 
			vPos += XMVectorScale(vMoveX, speed);
		}*/

		//オブジェクトの角度を変更
		transform_.rotate_.y = XMConvertToDegrees(angle);

		//結果を代入
		XMStoreFloat3(&_transform->position_, vPos);
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
