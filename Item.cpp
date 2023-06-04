#include "Item.h"
#include "Engine/Model.h"
#include <string>
#include <list>
using std::string;
using std::list;


//アイテムが保持している情報
struct ItemData {
	//モデルデータ(○〇.fbx)
	string fileName_;

	//モデル番号(handle)
	int hModel_;
	
	//アイテムの役割(keyItem or ScoreItem)
	int role_;

	//アイテムの所属？(野球グッズとか、...)
	int type_;
};

Item::Item(GameObject* parent)
	: GameObject(parent, "PlayScene"),hModels{}
{
}

void Item::Initialize()
{
	string fileNames[] = {"",""};

	for (int i = 0; i < 10; i++) {
		hModels[i] = Model::Load(fileNames[i]);
	}
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
