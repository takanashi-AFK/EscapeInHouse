#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
	int hModel_;
	int s = 1;
	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;
	XMVECTOR dirction_;

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
	/// �J�����̕����x�N�g����ݒ肷��
	/// </summary>
	/// <param name="_dir">�J�����̕����x�N�g��</param>
	void SetDirction(XMVECTOR _dir) { this->dirction_ = _dir; }

	/// <summary>
	/// ����L�����N�^�[�̈ړ�����
	/// </summary>
	/// <param name="_transform">�ʒu�A�����A�g�嗦�Ȃǂ̏��</param>
	void CharacterMove(Transform* _transform);

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


	//�K�v�ȋ@�\
	/*
	*	����
	*	�ǂ�F������
	*	�A�C�e����F������
	*	�A�C�e�����E��
	*	�A�C�e�����g��
	*	�A�C�e�����̂Ă�
	*/

};

