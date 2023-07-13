#include "Player.h"
#include"Stage.h"
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

	Stage* pStage = (Stage*)FindObject("Stage");
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	XMFLOAT3 stagePos = pStage->GetPosition();

	Rect4 R = pStage->GetRect(stagePos, 10, 10);//Mayaのサイズで確認とれてる yellowfloorは10,10
	//Debug::Log(GetPosition().x,true);
	//Debug::Log(GetPosition().z,true);

	if (pStage->IsInRect(transform_.position_,R))
		Debug::Log("True", true);

}

//開放
void Player::Release()
{
}
