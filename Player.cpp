#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

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
}

//�X�V
void Player::Update()
{
	//���������x�N�g�����擾
	XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

	//�ړ����x
	float speed = 0.1f;

	//������x�N�g��X
	XMVECTOR vMoveZ = { 0.0f,0.0f,speed,0.0f };
	XMVECTOR vMoveX = { speed,0.0f,0.0f,0.0f };

	//��ʑO���Ɉړ�
	if (Input::IsKey(DIK_W)) { vPos += vMoveZ; }
	//��ʉE���Ɉړ�
	if (Input::IsKey(DIK_A)) { vPos -= vMoveX; }
	//��ʌ���Ɉړ�
	if (Input::IsKey(DIK_S)) { vPos -= vMoveZ; }
	//��ʍ����Ɉړ�
	if (Input::IsKey(DIK_D)) { vPos += vMoveX; }

	//�ړ��x�N�g���̐��K��
	XMVector3Normalize(vPos);
	//���݂̈ʒu���ړ��x�N�g���ɂ��炷
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
