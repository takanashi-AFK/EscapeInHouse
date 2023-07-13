#include "StartScene.h"
#include "Engine/Input.h"

StartScene::StartScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void StartScene::Initialize()
{
	//ボタンインスタンスの作成
	
	//ボタンの位置を設定

	//シーン変更機能を初期化インスタンスを作成
	
}

void StartScene::Update()
{
	static bool isChangeNow;
	isChangeNow = false;

	//シーン移動演出(ボタンが押されたら)
	if (Input::IsKeyDown(DIK_SPACE)) {
		isChangeNow = true;
		if (isChangeNow) {
			//画像くるくる処理をする
			pSC = Instantiate<SceneChange>(this);
			pSC->SetFade(false);
			pSC->ChangeScene(SCENE_ID_PLAY);
			pSC->ModifySC(SC_LATTICE, 120);

			//画像くるくる処理が終わった
			
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
