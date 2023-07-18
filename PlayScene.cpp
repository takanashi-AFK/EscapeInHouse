#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include"Engine/Camera.h"
#include"OrgCam.h"
//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	//学校の環境でカメラセットできるか検証してみよう
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<OrgCam>(this);
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
