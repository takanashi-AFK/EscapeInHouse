#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Button.h"

//�e�X�g�V�[�����Ǘ�����N���X
class TitleScene : public GameObject
{
	Text* pText;			//�}�E�X�̈ʒu��"�����I"�ɕ\�������Ă��܂��B
	const float imageY = 256;
	const float imageX = 512;
	float scaleX, scaleY;
	XMFLOAT3 mousePos_;		//���̕ϐ��Ƀ}�E�X�̍��W�������܂��B

	Button* btn = Instantiate<Button>(this);	//�{�^���N���X�̃A�h���X


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