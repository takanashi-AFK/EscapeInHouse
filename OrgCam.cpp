#include "OrgCam.h"
#include "Player.h"
#include "Stage.h"
#include"Engine/Camera.h"
//�R���X�g���N�^
OrgCam::OrgCam(GameObject* parent)
	: GameObject(parent, "OrgCam")
{
}

//������
void OrgCam::Initialize()
{
	Player* pPlayer = (Player*)FindObject("Player");
	XMFLOAT3  pPos = pPlayer->GetPosition();
	CAMERA_DATA Cam1;
	//���J�����Z�b�g
	//Cam1.camPos_.x = pPos.x ;
	//Cam1.camPos_.y = pPos.y + 1;
	//Cam1.camPos_.z = pPos.z;

	//Cam1.camTarget_ = Cam1.camPos_;

	camPos_ = XMFLOAT3(0, 10, -10);
	camTarget_ = pPos;

	Camera::SetPosition(camPos_);
	Camera::SetTarget(camTarget_);
}

//�X�V
void OrgCam::Update()
{
}

//�`��
void OrgCam::Draw()
{
}

//�J��
void OrgCam::Release()
{
}
