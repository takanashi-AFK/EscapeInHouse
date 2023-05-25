#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

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
}

//更新
void Player::Update()
{
	//向き方向ベクトルを取得
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

	//移動速度
	float speed = 0.1f;

	//空方向ベクトルX
	XMVECTOR vMoveZ = { 0.0f,0.0f,speed,0.0f };
	XMVECTOR vMoveX = { speed,0.0f,0.0f,0.0f };

	//画面前方に移動
	if (Input::IsKey(DIK_W)) { vPos += vMoveZ; }
	//画面右側に移動
	if (Input::IsKey(DIK_A)) { vPos -= vMoveX; }
	//画面後方に移動
	if (Input::IsKey(DIK_S)) { vPos -= vMoveZ; }
	//画面左側に移動
	if (Input::IsKey(DIK_D)) { vPos += vMoveX; }

	//移動ベクトルの正規化
	XMVector3Normalize(vPos);
	//現在の位置を移動ベクトルにずらす
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
