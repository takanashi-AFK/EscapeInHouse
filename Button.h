#include "Engine/GameObject.h"
#include "Engine/Image.h"
#include "Engine/Transform.h"


//�S�_���i�[����\����
struct Rect4
{
    XMFLOAT3 TL, TR, BL, BR;
};

class Button
    :public GameObject
{
private:
    int hPict_;  //�摜handle
    Rect4 rect_; //�摜�̒��_�S������
    float width;
    float height;

    
public:
    //�R���X�g���N�^
    Button(GameObject* parent);

    //������
    void Initialize();

    //�X�V
    void Update();

    // �`��
    void Draw();

    //�J��
    void Release();

    //�ǂݍ��܂ꂽ�摜����e���_���擾����
    void SetRect(/*int _Picthandle*/);

    //�{�^���͈͓̔��ɃJ�[�\�������邩�𔻒肷��
    bool IsButton(XMFLOAT3 Mpos);
};