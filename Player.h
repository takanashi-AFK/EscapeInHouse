#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Player : public GameObject
{
	int hModel_;	//���f���ԍ�
	Text* pText;

	XMVECTOR cameraDirction_;	//�J��������

	//�폜�\��̕ϐ�
	XMFLOAT3 camPosition_;
	XMFLOAT3 camTarget_;
	int s = 0;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	Player() {};

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

