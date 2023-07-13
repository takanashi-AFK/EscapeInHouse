#pragma once
#include "Engine/GameObject.h"
struct MVSINGLE
{
    double x;
    double y;
};
//���j���[���Ǘ�����N���X
class SceneChangeAnim : public GameObject
{
    int hPict_;    //�摜�ԍ�
    XMFLOAT3 fromVec, toVec;
    double sinx;
    bool fade_, move_;
    MVSINGLE mv;
    bool animStats = true;
    
public:
    //�R���X�g���N�^
    SceneChangeAnim(GameObject* parent);

    //�f�X�g���N�^
    ~SceneChangeAnim();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    std::string getInfo();

    void ModifyRect(int x, int y, bool _fade);

    void animPlaying(bool animplay) { animStats = animplay; }
};