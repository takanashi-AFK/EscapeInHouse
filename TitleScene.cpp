#include "TitleScene.h"

#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), pText(nullptr),scaleX(0.7),scaleY(0.7),mousePos_(0, 0, 0)
{
}

//初期化
void TitleScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
	btn->Initialize();
}

//更新
void TitleScene::Update()
{
	mousePos_ = Input::GetMousePosition();
	mousePos_.x = mousePos_.x/1200;
	mousePos_.y = mousePos_.y/600;
	btn->SetRect();

	if (btn->IsButton(mousePos_)&&
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
	pText->Draw(30, 30, (int)mousePos_.x);
	pText->Draw(90, 30, (int)mousePos_.y);
}

//開放
void TitleScene::Release()
{
	pText->Release();
}
