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
		//�J���������̕ϊ�
		if (IsChangeMoveDir()) {
			SetMoveDirction(GetCamDirVector(camPosition_, camTarget_));
		}

		//���̏�����&���
		XMVECTOR vPos = XMLoadFloat3(&_transform->position_);
		float angle = atan2(XMVectorGetX(cameraDirction_), XMVectorGetZ(cameraDirction_));

		//�e���͎��̏���
		EachInputProsess(vPos, angle);

		//���f���̌�����ύX
		if(InputAnyWASD())
		transform_.rotate_.y = XMConvertToDegrees(angle);

		//���ʂ���
		XMStoreFloat3(&_transform->position_, vPos);
}

void Player::EachInputProsess(XMVECTOR& _vec, float& _angle)
{
	//���̓p�^�[���ꗗ
	/*
	* W		{ angle = Degree 0
	* WA	{ angle = Degree 45
	* A		{ angle = Degree 90
	* AS	{ angle = Degree 135
	* S		{ angle = Degree 180
	* SD	{ angle = Degree 225
	* D		{ angel = Degree 270
	* DW	{ angle = Degree 315
	*
	* �����_
	* �L�[���Q�ȏ㉟���ꂽ���ɈႤ�����Ɉڂ�Ȃ��悤�ɂ���ׂ��H
	* �Ή���
	* �L�[����ȏ㉟����Ă��Ȃ������m�F����֐���p��
	* �H�H�H
	*/

	//��������
	if (Input::IsKey(DIK_W)) {
		if (Input::IsKey(DIK_A))
			_angle -= XMConvertToRadians(45);
		else if (Input::IsKey(DIK_D))
			_angle -= XMConvertToRadians(315);
		else
			_angle -= XMConvertToRadians(0);
	}
	else if (Input::IsKey(DIK_A)) {
		if (Input::IsKey(DIK_S))
			_angle -= XMConvertToRadians(135);
		else
			_angle -= XMConvertToRadians(90);
	}
	else if (Input::IsKey(DIK_S)) {
		if (Input::IsKey(DIK_D))
			_angle -= XMConvertToRadians(225);
		else
			_angle -= XMConvertToRadians(180);
	}
	else if (Input::IsKey(DIK_D)) {
		_angle -= XMConvertToRadians(270);
	}

	//WASD�����ꂩ�̃L�[�������ꂽ�Ƃ�
	if (InputAnyWASD()) {
		XMVECTOR move = { 0,0,SPEED,0 };
		_vec += XMVector3TransformCoord(move, XMMatrixRotationY(_angle));
	}

}

bool Player::InputAnyWASD()
{
	if (Input::IsKey(DIK_W) ||
		Input::IsKey(DIK_A) ||
		Input::IsKey(DIK_S) ||
		Input::IsKey(DIK_D)) {
		return true;
	}
	return false;
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
