#include "StartScene.h"
#include "Engine/Input.h"

StartScene::StartScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void StartScene::Initialize()
{
	//�{�^���C���X�^���X�̍쐬
	
	//�{�^���̈ʒu��ݒ�

	//�V�[���ύX�@�\���������C���X�^���X���쐬
	
}

void StartScene::Update()
{
	static bool isChangeNow;
	isChangeNow = false;

	//�V�[���ړ����o(�{�^���������ꂽ��)
	if (Input::IsKeyDown(DIK_SPACE)) {
		isChangeNow = true;
		if (isChangeNow) {
			//�摜���邭�鏈��������
			pSC = Instantiate<SceneChange>(this);
			pSC->SetFade(false);
			pSC->ChangeScene(SCENE_ID_PLAY);
			pSC->ModifySC(SC_LATTICE, 120);

			//�摜���邭�鏈�����I�����
			
		}
		else {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_PLAY);

		}
	}
	
		


}

void StartScene::Draw()
{
}

void StartScene::Release()
{
}
