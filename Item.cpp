#include "Item.h"
#include "Engine/Model.h"
#include <string>
#include <list>
using std::string;
using std::list;


//�A�C�e�����ێ����Ă�����
struct ItemData {
	//���f���f�[�^(���Z.fbx)
	string fileName_;

	//���f���ԍ�(handle)
	int hModel_;
	
	//�A�C�e���̖���(keyItem or ScoreItem)
	int role_;

	//�A�C�e���̏����H(�싅�O�b�Y�Ƃ��A...)
	int type_;
};

Item::Item(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void Item::Initialize()
{
}

void Item::Update()
{
}

void Item::Draw()
{
}

void Item::Release()
{
}
