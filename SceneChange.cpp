#include "SceneChange.h"
#include "Engine/Debug.h"
#include "Engine/Image.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include <iostream>

//�R���X�g���N�^
SceneChange::SceneChange(GameObject* parent)
    :GameObject(parent, "SceneChange")
{

	//�G�t�F�N�g�摜�z�u�z��������� = nullptr
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 18; j++) {
			pChangeAnim[i][j] = nullptr;
		}
	}

	animpts = 0;
	nowFrame = 0;
	fade_ = false;
	mvSwitch = true;
	tileReset = true;
	hPict_ = -1;
	waitTime = 0;
	sinx = 0;
	val = 0;
}

//�f�X�g���N�^
SceneChange::~SceneChange()
{
}

//������
void SceneChange::Initialize()
{

}

//�X�V
void SceneChange::Update()
{
	//���݃t���[��
	if (scID == SC_LATTICE) {
	nowFrame++;
		if (!fade_) {
			//���S�����h��
			while (tileReset) {
				int y = 0;
				for (int x = animpts; y <= animpts; x--) {
					if (x >= 16) {
						y++;
						//Debug::Log("x��16�ȏ� y��+1");
						//Debug::Log(" x:"); Debug::Log(x); Debug::Log(" y:"); Debug::Log(y, true);
						continue;
					}
					if (y >= 9) {
						//Debug::Log("y��9�ȏ� �I���");
						//Debug::Log(" x:"); Debug::Log(x); Debug::Log(" y:"); Debug::Log(y, true);
						break;
					}
					//Debug::Log("animpts: ");
					//Debug::Log(animpts);
					//Debug::Log(" x:");
					//Debug::Log(x);
					//Debug::Log(" y:");
					//Debug::Log(y, true);
					pChangeAnim[x][y] = Instantiate<SceneChangeAnim>(GetParent());
					pChangeAnim[x][y]->ModifyRect(x, y, fade_);
					pChangeAnim[x][y]->animPlaying(false);
					y++;
				}
				if (animpts < 24) {
					animpts++;
					//Debug::Log("animpts+1", true);
				}
				else {
					tileReset = false;
					animpts = 0;
				}
			}
			//1f���ɋ󔒂ɂ��Ă���
			int y = 0;
			if (mvSwitch) {
				for (int x = animpts; y <= animpts; x--) {
					if (x >= 16) {
						y++;
						//Debug::Log("x��16�ȏ� y��+1");
						//Debug::Log(" x:"); Debug::Log(x); Debug::Log(" y:"); Debug::Log(y, true);
						continue;
					}
					if (y >= 9) {
						//Debug::Log("y��9�ȏ� �I���");
						//Debug::Log(" x:"); Debug::Log(x); Debug::Log(" y:"); Debug::Log(y, true);
						break;
					}
					//Debug::Log("animpts: ");
					//Debug::Log(animpts);
					//Debug::Log(" x:");
					//Debug::Log(x);
					//Debug::Log(" y:");
					//Debug::Log(y, true);
					pChangeAnim[x][y]->animPlaying(true);
					y++;
				}
			}
			if (animpts < 24) {
				animpts++;
				//Debug::Log("animpts+1", true);
			}
			else {
				mvSwitch = false;
			}
			//200f�őS������
			if (nowFrame > 200) {
				KillAllChildren();
				KillMe();
			}
		}
		
		if (fade_) {
			int y = 0;
			if (mvSwitch) {
				for (int x = animpts; y <= animpts; x--) {
					if (x >= 16) {
						y++;
						continue;
					}
					if (y >= 9) {
						break;
					}

					pChangeAnim[x][y] = Instantiate<SceneChangeAnim>(GetParent());
					pChangeAnim[x][y]->ModifyRect(x, y, fade_);
					y++;
				}
			}
			if (animpts < 24) {
				animpts++;
				
			}
			else {
				mvSwitch = false;
			}
			if (nowFrame > 40) {
				SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
				pSceneManager->ChangeScene(sceneName);
			}
		}
	}

	if (scID == SC_BLACK || scID == SC_WHITE) {
		//����
		if (!fade_) {
			sinx += 0.0625f;
			//�E��
			if (sinx > M_PI / 2) {
				KillAllChildren();
				KillMe();
			}
			Image::SetAlpha(hPict_, 255 - 255.0f * std::sin(sinx));
		}
		//�ʂ�
		if (fade_) {
			if (!nowFrame) {
				sinx += 0.0625f;
				//���
				if (sinx > M_PI / 2) {
					sinx = M_PI / 2;
					nowFrame = 1;
				}
				//255��0
				val = 255.0f * std::sin(sinx);
				
				Image::SetAlpha(hPict_, val);
			}
			else {
				if (ReturnFrame()) {
					SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
					pSceneManager->ChangeScene(sceneName);
				}
				else {
					nowFrame++;
				}
			}
		}
	}
}

//�`��
void SceneChange::Draw()
{
	if (scID == SC_BLACK || scID == SC_WHITE) {
		Image::SetTransform(hPict_, transform_);
		Image::Draw(hPict_);
	}
}

//�J��
void SceneChange::Release()
{
}

bool SceneChange::ReturnFrame()
{
	if (nowFrame < waitTime)
		return false;
	else return true;
}

void SceneChange::ChangeScene(SCENE_ID sceneName_) {
	sceneName = sceneName_;
}

void SceneChange::ModifySC(SCENE_CHANGE_ID sc, int _wait)
{
	scID = sc;
	waitTime = _wait;
	Init();
}

void SceneChange::Init()
{
	switch (scID) {
	case SC_BLACK:
		hPict_ = Image::Load("black.png");
		assert(hPict_ >= 0);
		break;
	case SC_WHITE:
		hPict_ = Image::Load("white.png");
		assert(hPict_ >= 0);
		break;
	}
}
