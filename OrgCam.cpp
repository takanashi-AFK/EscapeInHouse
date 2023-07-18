#include "OrgCam.h"
#include "Player.h"
#include "Stage.h"
#include"Engine/Camera.h"
//コンストラクタ
OrgCam::OrgCam(GameObject* parent)
	: GameObject(parent, "OrgCam")
{
}

//初期化
void OrgCam::Initialize()
{
	Player* pPlayer = (Player*)FindObject("Player");
	XMFLOAT3  pPos = pPlayer->GetPosition();
	CAMERA_DATA Cam1;
	//仮カメラセット
	//Cam1.camPos_.x = pPos.x ;
	//Cam1.camPos_.y = pPos.y + 1;
	//Cam1.camPos_.z = pPos.z;

	//Cam1.camTarget_ = Cam1.camPos_;

	camPos_ = XMFLOAT3(0, 10, -10);
	camTarget_ = pPos;

	Camera::SetPosition(camPos_);
	Camera::SetTarget(camTarget_);
}

//更新
void OrgCam::Update()
{
}

//描画
void OrgCam::Draw()
{
}

//開放
void OrgCam::Release()
{
}
