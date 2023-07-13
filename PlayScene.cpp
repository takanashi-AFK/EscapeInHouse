#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include"Engine/Camera.h"
//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	//���J�����Z�b�g
	XMFLOAT3 camPosition_ = { 0.0f,7.0f,-13.0f };
	XMFLOAT3 camTarget_ = { 0.0f,1.0f,2.0f };

	Camera::SetPosition(camPosition_);
	Camera::SetTarget(camTarget_);
	//�w�Z�̊��ŃJ�����Z�b�g�ł��邩���؂��Ă݂悤
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
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
