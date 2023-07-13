#pragma once
#include "Engine/GameObject.h"
#include "SceneChangeAnim.h"
#include "Engine/SceneManager.h"

enum SCENE_CHANGE_ID {
    SC_LATTICE = 0,
    SC_BLACK,
    SC_WHITE,
};
//�V���`�F�̏W�����Ǘ�����N���X
class SceneChange : public GameObject
{
    //��΂�����������̕��@�Œ萔����Ȃ��Ă��������� ���͎蓮�ł��� �����Ǝ��Ԃ�����Ȃ�
    SceneChangeAnim* pChangeAnim[32][18];
    int animpts;
    int nowFrame;
    bool fade_;
    bool mvSwitch;
    bool tileReset;
    SCENE_ID sceneName;

    int hPict_;
    int scID;
    int waitTime;
    double sinx;
    float val;
public:
    //�R���X�g���N�^
    SceneChange(GameObject* parent);

    //�f�X�g���N�^
    ~SceneChange();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetFade(bool _fade) { fade_ = _fade; }
    //SetFade�͔p���\��
    void SetState(SCENE_CHANGE_ID _mode, bool _fade) {
        
    }
    bool ReturnFrame();

    void ChangeScene(SCENE_ID sceneName_);
    void ModifySC(SCENE_CHANGE_ID sc, int _wait = 0);
    void Init();
};