#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"

//�e�X�g�V�[�����Ǘ�����N���X
struct CAMERA_DATA {
	XMFLOAT3 camPos_;//�ʒu 
	XMFLOAT3 camTarget_; // ���イ���Ă�
	Rect4 camArea_;
	int camNumber;
};
class OrgCam : public GameObject
{
private:


public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	OrgCam(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};