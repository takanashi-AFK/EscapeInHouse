#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�e�X�g�V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	
	XMFLOAT3 mousePos;		//���̕ϐ��Ƀ}�E�X�̍��W�������܂��B
	bool is_same_position;	//�������W�ɂ���Ƃ��ɔ������܂�
	Text* pText;			//�}�E�X�̈ʒu��"�����I"�ɕ\�������Ă��܂��B

	enum STATES{				//�o��������G��ς��邽�߂Ɏg�p���܂�
		APict = 0,
		BPict,

		MAX
	};
	int hPict_[STATES::MAX];
	int state_;			//�X�e�[�^�X��ω�������Ƃ��Ɏg�p���܂�

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};