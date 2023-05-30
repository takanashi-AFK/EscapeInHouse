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

	//�J�����f�[�^�̎擾
	#if 0
	{
		
	}
	#endif

	//���J�����Z�b�g
	camPosition_ = { 0.0f,3.0f,-5.0f };
	camTarget_ = { 0.0f,0.0f,1.0f };

	//�J�����̕����x�N�g�����擾
	SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);

}

//�X�V
void Player::Update()
{
	//�ړ�����
	CharacterMove(&transform_);

	//�J����
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

		//���̏�����
		XMVECTOR vDirZ = { 0,0,1,0 };
		XMVECTOR vDirX = { 1,0,0,0 };
		XMVECTOR vMoveZ = moveDirction_;
		XMVECTOR vMoveX = XMVector3TransformCoord(moveDirction_, XMMatrixRotationY(XMConvertToRadians(90)));
		XMVECTOR vPos = XMLoadFloat3(&_transform->position_);
		float speed = SPEED;
		//float dot = 0.0f;

		XMVECTOR vec = {0,0,0,0};

		//������s
		if (Input::IsKey(DIK_W)) { 
			vPos += XMVectorScale(vMoveZ, speed);
			vec = XMVectorScale(vMoveZ, speed);
		}

		if (Input::IsKey(DIK_A)) { 
			vPos -= XMVectorScale(vMoveX, speed); 
			vec = XMVectorScale(vMoveX, speed);

		}
		
		if (Input::IsKey(DIK_S)) { 
			vPos -= XMVectorScale(vMoveZ, speed);
			vec = XMVectorScale(vMoveZ, speed);

		}
		
		if (Input::IsKey(DIK_D)) { 
			vPos += XMVectorScale(vMoveX, speed);
			vec = XMVectorScale(vMoveX, speed);

		}

		//�I�u�W�F�N�g�̊p�x��ύX
		float dot = XMVectorGetX(XMVector3Dot(XMVector3Normalize(vDirX), XMVector3Normalize(vec)));
		float radian = acos(dot);
		float angle = XMConvertToDegrees(radian);
		transform_.rotate_.y = angle;

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
