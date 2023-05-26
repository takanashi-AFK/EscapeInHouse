#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#include "Engine/Camera.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//������
void Player::Initialize()
{
	hModel_ = Model::Load("defaultCharacter.fbx");
	assert(hModel_ >= 0);

	//���J�����Z�b�g
	camPosition_ = { -10.0f,5.0f,10.0f };
	camTarget_ = { 0.0f,0.0f,0.0f };

	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);

}

//�X�V
void Player::Update()
{
	//���������x�N�g�����擾
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

	//�ړ����x
	float speed = 0.1f;

	//�J�����̕����x�N�g�����擾&������
	XMFLOAT3 end = { camTarget_.x,0.0f,camTarget_.z };
	XMFLOAT3 begin = { camPosition_.x,0.0f,camPosition_.z };
	XMVECTOR camDir = XMVectorSubtract(XMLoadFloat3(&end), XMLoadFloat3(&begin));
	XMVECTOR vMoveZ = XMVector3Normalize(camDir);
	XMVECTOR vMoveX = XMVector3Normalize(XMVector3TransformCoord(camDir, XMMatrixRotationY(XMConvertToRadians(90))));

	//��ʑO���Ɉړ�
	if (Input::IsKey(DIK_W)) { vPos += XMVectorScale(vMoveZ,speed);}
	//��ʉE���Ɉړ�
	if (Input::IsKey(DIK_A)) { vPos -= XMVectorScale(vMoveX, speed);}
	//��ʌ���Ɉړ�
	if (Input::IsKey(DIK_S)) { vPos -= XMVectorScale(vMoveZ, speed);}
	//��ʍ����Ɉړ�
	if (Input::IsKey(DIK_D)) { vPos += XMVectorScale(vMoveX,speed);}

	XMStoreFloat3(&transform_.position_, vPos);
}

//�`��
void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}
