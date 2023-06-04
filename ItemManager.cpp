#include "ItemManager.h"
#include "Item.h"
#include <list>
using std::list;

void ItemManager::Initialize()
{
	list<Item*> ItemList = { 
		Instantiate<Item>(this),
		Instantiate<Item>(this),
		Instantiate<Item>(this),
	};
}

void ItemManager::Update()
{
}
