#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
	int hModel_;

	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;

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
	/// 2�_�����ԃx�N�g�������߂Ēl��Ԃ�
	/// </summary>
	/// <param name="_vecA">�n�_</param>
	/// <param name="_vecB">�I�_</param>
	/// <returns>�x�N�g��AB</returns>
	XMVECTOR CalucurateVector(XMVECTOR _vecA, XMVECTOR _vecB);

	/// <summary>
	/// 2�_�����ԃx�N�g�������߂Ēl��Ԃ�
	/// </summary>
	/// <param name="_posA">�n�_</param>
	/// <param name="_posB">�I�_</param>
	/// <returns>�x�N�g��AB</returns>
	XMVECTOR CalucurateVector(XMFLOAT3 _posA, XMFLOAT3 _posB);
};

