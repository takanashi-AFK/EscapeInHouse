#include "TitleScene.h"

#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

//コンストラクタ
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene"),mousePos(0,0,0), pText(nullptr)
{
}

//初期化
void TitleScene::Initialize()
{
	//file name
	std::string fileName[] = { "ButtonA_1.png","ButtonA_2.png" };
	for (int l = 0; l < MAX; l++) {
		hPict_[l] = Image::Load(fileName[l]);
	}

	transform_.scale_ = XMFLOAT3(0.7, 0.7, 0);
	transform_.position_.y = -0.5f;

	pText = new Text;
	pText->Initialize();
}

//更新
void TitleScene::Update()
{
	mousePos = Input::GetMousePosition();
	if ((mousePos.x >= 465) && (mousePos.x <= 812)
		&&(mousePos.y >= 456) &&(mousePos.y <= 621)) {
		is_same_position = true;
	}

	if (is_same_position = true && Input::IsMouseButton(0)) {
		//画像切り替え処理をここに
		if (state_ < 2) { state_ = 0; }
		state_++;

		//
		//ここから下にシーン変更を呼びます。
		//

		//ここで暗転をお願いします！！！！！

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
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

//開放
void TitleScene::Release()
{
}
