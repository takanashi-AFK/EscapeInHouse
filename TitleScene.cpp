#include "TitleScene.h"

#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Button.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),mousePos(0,0,0), pText(nullptr),scaleX(0.7),scaleY(0.7)
{
}

//������
void TitleScene::Initialize()
{
	//file name
	std::string fileName[] = { "ButtonA_1.png","ButtonA_2.png" };
	for (int l = 0; l < MAX; l++) {
		hPict_[l] = Image::Load(fileName[l]);
	}


	XMFLOAT3 imgPosition_(0.0f, -0.5f, 0.0f); //�{�^���̃|�W�V�����������ɐݒ�
	btn->SetPosition(imgPosition_);
	btn->ButtonSize(imageX,imageY,scaleX,scaleY);
	pText = new Text;
	pText->Initialize();
}

//�X�V
void TitleScene::Update()
{
	mousePos = Input::GetMousePosition();
	//if ((mousePos.x >= 465) && (mousePos.x <= 812)
	//	&&(mousePos.y >= 456) &&(mousePos.y <= 621)) {
	//	is_same_position = true;
	//}
	if (btn->ButtonIsHit(mousePos))
	{
		//�摜�؂�ւ�������������
		if (state_ < 2) { state_ = 0; }
		state_++;


		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}

}

//�`��
void TitleScene::Draw()
{
	switch(state_)
	{
	case APict:
		Image::SetTransform(hPict_[APict], transform_);
		Image::Draw(hPict_[APict]);
		break;

	case BPict:
		Image::SetTransform(hPict_[BPict], transform_);
		Image::Draw(hPict_[BPict]);
	}


	pText->Draw(30, 30, (int)mousePos.x);
	pText->Draw(90, 30, (int)mousePos.y);
}

//�J��
void TitleScene::Release()
{
}
