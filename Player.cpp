#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/Camera.h"

const float SPEED = 0.1f;//移動速度


//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), pText(nullptr)
{
}

//初期化
void Player::Initialize()
{

	pText = new Text;
	pText->Initialize();

	//モデルデータのロード
	hModel_ = Model::Load("Stick.fbx");
	assert(hModel_ >= 0);

	//transform_.rotate_.y = 450;

	//仮カメラセット
	camPosition_ = { 0.0f,3.0f,0.0f };
	camTarget_ = { 0.0f,3.0f,0.0f };

	//Camera::SetPosition(camPosition_);
	//Camera::SetTarget(camTarget_);
	//学校の環境でカメラセットできるか検証してみよう

}

//更新
void Player::Update()
{
	if (Input::IsKey(DIK_W)) {
		transform_.position_.z += 0.2f;
	}
	if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.2f;
	}
	if (Input::IsKey(DIK_S)) {
		transform_.position_.z -= 0.2f;
	}
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.2f;
	}

}

//描画
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	Debug::Log(GetPosition().x,true);
	Debug::Log(GetPosition().z,true);

}

//開放
void Player::Release()
{
}
