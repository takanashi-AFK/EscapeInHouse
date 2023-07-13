#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include"Engine/Camera.h"
//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	//仮カメラセット
	XMFLOAT3 camPosition_ = { 0.0f,7.0f,-13.0f };
	XMFLOAT3 camTarget_ = { 0.0f,1.0f,2.0f };

	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);
	//学校の環境でカメラセットできるか検証してみよう
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
