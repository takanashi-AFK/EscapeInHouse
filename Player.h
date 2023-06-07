#pragma once
#include "Engine/GameObject.h"

namespace Inventory
{
	/// <summary>
	/// �A�C�e�����擾���鏈��
	/// </summary>
	void GetItem();

	/// <summary>
	/// �A�C�e�����g�p���鏈��
	/// </summary>
	void UseItem();

	/// <summary>
	/// �A�C�e����������鏈��
	/// </summary>
	void DropItem();
}


class Player : public GameObject
{
	int hModel_;	//���f���ԍ�

	XMVECTOR cameraDirction_;	//�J��������

	//�폜�\��̕ϐ�
	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;
	int s = 0;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// �v���C���[�̈ړ������x�N�g����ݒ肷��
	/// </summary>
	/// <param name="_dir">�J�����̕����x�N�g��</param>
	void SetMoveDirction(XMVECTOR _dir) { this->cameraDirction_ = _dir; }

	/// <summary>
	/// ����L�����N�^�[�̈ړ�����
	/// </summary>
	/// <param name="_transform">�ʒu�A�����A�g�嗦�Ȃǂ̏��</param>
	void CharacterMove(Transform* _transform);

	/// <summary>
	/// �e�L�[�̓��͎��ɍs���鏈��
	/// </summary>
	/// <param name="_vec">�L�����N�^�[�̈ʒu�x�N�g��</param>
	/// <param name="_angle">�L�����N�^�[�̐i�s����</param>
	void EachInputProsess(XMVECTOR& _vec,float& _angle);

	/// <summary>
	/// WASD�̂����ꂩ�̃L�[�����͂��ꂽ��
	/// </summary>
	/// <returns>���͂���Ă����true</returns>
	bool InputAnyWASD();

	/// <summary>
	/// �J�����̕����x�N�g�����擾
	/// </summary>
	/// <param name="_camPosition">�J�����̈ʒu</param>
	/// <param name="_camTarget">�J�����̏œ_</param>
	/// <returns>�J�����̕����x�N�g��</returns>
	XMVECTOR GetCamDirVector(XMFLOAT3 _camPosition, XMFLOAT3 _camTarget);

	/// <summary>
	/// �ړ�������ύX���ėǂ���
	/// </summary>
	/// <returns>�ύX���ėǂ����true</returns>
	bool IsChangeMoveDir();

	/// <summary>
	/// �A�C�e���֘A�S�ʂ̏���
	/// </summary>
	void ItemRelated();

	

	//�K�v�ȋ@�\�E�s��
	/*
	*	����
	*	�A�C�e�������܂�
	*	�A�C�e�����E��
	*	�A�C�e�����g��
	*	�A�C�e�����̂Ă�
	*/

};

