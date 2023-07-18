#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include"Engine/Camera.h"
#include"OrgCam.h"
//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	//�w�Z�̊��ŃJ�����Z�b�g�ł��邩���؂��Ă݂悤
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<OrgCam>(this);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
