#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

#include "Engine/Camera.h"

const float SPEED = 0.1f;//�ړ����x


//�R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player")
{
}

//������
void Player::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model/Character.fbx");
	assert(hModel_ >= 0);

	//transform_.rotate_.y = 450;

	//���J�����Z�b�g
	camPosition_ = { 0.0f,3.0f,-5.0f };
	camTarget_ = { 0.0f,0.0f,1.0f };

	//�J�����̕����x�N�g�����擾
	SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);

	dot = 0.0f;
}

//�X�V
void Player::Update()
{
	//�ړ�����
	CharacterMove(&transform_);

	//�A�C�e���̏���
	ItemRelated();
	
	//���J����
	{
		
		if (Input::IsKeyDown(DIK_SPACE)) {
			if (s > 4) { s = 0; }
			s++;
		}

		switch (s)
		{
		case 0:	//�L�����N�^�[�w��
			camPosition_ = { 0.0f,3.0f,-5.0f };
			camTarget_ = { 0.0f,0.0f,1.0f };
			break;
		case 1:	//�L�����N�^�[����
			camPosition_ = { 0.0f,3.0f,5.0f };
			camTarget_ = { 0.0f,0.0f,-1.0f };
			break;
		case 2:	//�L�����N�^�[�E��
			camPosition_ = { 5.0f,3.0f,0.0f };
			camTarget_ = { -1.0f,0.0f,0.0f };
			break;
		case 3://�L�����N�^�[����
			camPosition_ = { -5.0f,3.0f,0.0f };
			camTarget_ = { 1.0f,0.0f,0.0f };
			break;
		case 4://�L�����N�^�[�E�O�΂�
			camPosition_ = { 5.0f,3.0f,-5.0f };
			camTarget_ = { -1.0f,0.0f,1.0f };
			break;
		case 5://�L�����N�^�[�����΂�
			camPosition_ = { -5.0f,3.0f,5.0f };
			camTarget_ = { 1.0f,0.0f,-1.0f };
			break;
		}
		Camera::SetPosition(camPosition_);
		Camera::SetTarget(camTarget_);
	}

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

void Player::CharacterMove(Transform* _transform)
{
		//�ړ������̕ϊ�
		if (IsChangeMoveDir()) {
			SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
		}

		//���̏�����&���
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
		
		////������s
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

		//�I�u�W�F�N�g�̊p�x��ύX
		transform_.rotate_.y = XMConvertToDegrees(angle);

		//���ʂ���
		XMStoreFloat3(&_transform->position_, vPos);
}

XMVECTOR Player::GetCamDirVector(XMFLOAT3 _camPosition, XMFLOAT3 _camTarget)
{
#if 1
	//y���W���O�ŏ�����
	_camPosition.y = 0.0f;
	_camTarget.y = 0.0f;

	//XMFLOAT3 �� XMVECTOR�ɕϊ�
	XMVECTOR begin = XMLoadFloat3(&_camPosition);
	XMVECTOR end = XMLoadFloat3(&_camTarget);

	//�����x�N�g�����擾
	XMVECTOR camDirection = XMVectorSubtract(end, begin);

	//������������
	camDirection = XMVector3Normalize(camDirection);

	//�߂�l
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

	//�J�������؂�ւ������
	if (isCamChanege) {
		//�ړ��L�[�����͂���Ă��Ȃ����
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
	//�A�C�e���擾����
	Inventory::GetItem();
	//�A�C�e���g�p����
	Inventory::UseItem();
	//�A�C�e����������
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
