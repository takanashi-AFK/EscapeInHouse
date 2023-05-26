#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#include "Engine/Camera.h"

//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//初期化
void Player::Initialize()
{
	hModel_ = Model::Load("defaultCharacter.fbx");
	assert(hModel_ >= 0);

	//仮カメラセット
	camPosition_ = { -10.0f,5.0f,10.0f };
	camTarget_ = { 0.0f,0.0f,0.0f };

	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);

}

//更新
void Player::Update()
{
	//向き方向ベクトルを取得
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

	//移動速度
	float speed = 0.1f;

	//カメラの方向ベクトルを取得&初期化
	XMFLOAT3 end = { camTarget_.x,0.0f,camTarget_.z };
	XMFLOAT3 begin = { camPosition_.x,0.0f,camPosition_.z };
	XMVECTOR camDir = XMVectorSubtract(XMLoadFloat3(&end), XMLoadFloat3(&begin));
	XMVECTOR vMoveZ = XMVector3Normalize(camDir);
	XMVECTOR vMoveX = XMVector3Normalize(XMVector3TransformCoord(camDir, XMMatrixRotationY(XMConvertToRadians(90))));

	//画面前方に移動
	if (Input::IsKey(DIK_W)) { vPos += XMVectorScale(vMoveZ,speed);}
	//画面右側に移動
	if (Input::IsKey(DIK_A)) { vPos -= XMVectorScale(vMoveX, speed);}
	//画面後方に移動
	if (Input::IsKey(DIK_S)) { vPos -= XMVectorScale(vMoveZ, speed);}
	//画面左側に移動
	if (Input::IsKey(DIK_D)) { vPos += XMVectorScale(vMoveX,speed);}

	XMStoreFloat3(&transform_.position_, vPos);
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
