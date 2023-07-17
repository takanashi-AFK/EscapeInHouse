#include "TitleScene.h"

#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Button.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), pText(nullptr),scaleX(0.7),scaleY(0.7),mousePos_(0, 0, 0)
{
}

//������
void TitleScene::Initialize()
{
	XMFLOAT3 imgPosition_(0.0f, -0.5f, 0.0f); //�{�^���̃|�W�V�����������ɐݒ�

	btn->SetPosition(imgPosition_);
	btn->ButtonSize(imageX, imageY, scaleX, scaleY);

}

//�X�V
void TitleScene::Update()
{
	mousePos_ = Input::GetMousePosition();

	if (btn->ButtonIsHit(mousePos_)&&
		(Input::IsMouseButton(0)))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

}

//�`��
void TitleScene::Draw()
{
	btn->Draw();
	//pText->Draw(30, 30, (int)mousePos_.x);
	//pText->Draw(90, 30, (int)mousePos_.y);
}

//�J��
void TitleScene::Release()
{
}
