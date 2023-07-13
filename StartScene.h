#pragma once
#include "Engine/GameObject.h"
#include "SceneChange.h"

//�e�X�g�V�[�����Ǘ�����N���X
class StartScene : public GameObject
{
	SceneChange* pSC;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	StartScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};