#include "TitleScene.h"

#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Button.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), pText(nullptr),scaleX(0.7),scaleY(0.7),mousePos_(0, 0, 0)
{
}

//初期化
void TitleScene::Initialize()
{
	XMFLOAT3 imgPosition_(0.0f, -0.5f, 0.0f); //ボタンのポジションをここに設定

	btn->SetPosition(imgPosition_);
	btn->ButtonSize(imageX, imageY, scaleX, scaleY);

}

//更新
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

//描画
void TitleScene::Draw()
{
	btn->Draw();
	//pText->Draw(30, 30, (int)mousePos_.x);
	//pText->Draw(90, 30, (int)mousePos_.y);
}

//開放
void TitleScene::Release()
{
}
