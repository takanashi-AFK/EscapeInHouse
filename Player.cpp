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

	//カメラデータの取得
	#if 0
	{
		
	}
	#endif

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

	//カメラ
	{
		
		if (Input::IsKeyDown(DIK_SPACE)) {
			if (s > 2) { s = 0; }
			s++;
		}

		switch (s)
		{
		case 1:	
			camPosition_ = { 0.0f,3.0f,-5.0f };
			camTarget_ = { 0.0f,0.0f,1.0f };
			break;
		case 2:	
			camPosition_ = { 0.0f,3.0f,5.0f };
			camTarget_ = { 0.0f,0.0f,-1.0f };
			break;
		case 3:	
			camPosition_ = { 10.0f,3.0f,-5.0f };
			camTarget_ = { 0.0f,0.0f,1.0f };
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

		//情報の初期化
		XMVECTOR vDirZ = { 0,0,1,0 };
		XMVECTOR vMoveZ = moveDirction_;
		XMVECTOR vMoveX = XMVector3TransformCoord(moveDirction_, XMMatrixRotationY(XMConvertToRadians(90)));
		XMVECTOR vPos = XMLoadFloat3(&_transform->position_);
		float speed = SPEED;

		//動作実行
		if (Input::IsKey(DIK_W)) { 
			vPos += XMVectorScale(vMoveZ, speed);
			//transform_.rotate_.y = 0;
		}

		if (Input::IsKey(DIK_A)) { 
			vPos -= XMVectorScale(vMoveX, speed); 
			//transform_.rotate_.y = -90;
		}
		
		if (Input::IsKey(DIK_S)) { 
			vPos -= XMVectorScale(vMoveZ, speed); 
			//transform_.rotate_.y = 180;
		}
		
		if (Input::IsKey(DIK_D)) { 
			vPos += XMVectorScale(vMoveX, speed);
			//transform_.rotate_.y = 90;

		}

		//オブジェクトの角度を変更
		/*float dot = XMVectorGetX(XMVector3Dot(vDirZ, vPos));
		float radian = acos(dot);
		float angle = XMConvertToDegrees(radian);
		transform_.rotate_.y = angle;*/

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
