#include "LinkedList.h"
#include <stdexcept>

template<class ItemType>
LinkedList<ItemType>::LinkedList()
{
	length = 0;
	listData = nullptr;
	currentPos = nullptr;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	NodeType<ItemType>* tempNode;
	currentPos = listData;
	while (currentPos != nullptr)
	{
		tempNode = currentPos;
		currentPos = currentPos->next;
		delete tempNode;
	}
}

template<class ItemType>
void LinkedList<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempNode;
	currentPos = listData;
	while (currentPos != nullptr)
	{
		tempNode = currentPos;
		currentPos = currentPos->next;
		delete tempNode;
	}
}

template<class ItemType>
bool LinkedList<ItemType>::IsFull() const
{
	NodeType<ItemType>* location;
	try
	{
		// 새로운 Node를 받는 것이 가능함 => false
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		// Node를 받으려 해도 안 받아질 때 => true
		return true;
	}
}

template<class ItemType>
int LinkedList<ItemType>::LengthIs() const
{
	return length;
}

template<class ItemType>
void LinkedList<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;
	location = listData;
	found = false;
	
	moreToSearch = (location != nullptr);
	while (moreToSearch && !found)
	{
		if (item == location->info)
		{
			item = location->info;
			found = true;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}
	}
}

template<class ItemType>
void LinkedList<ItemType>::InsertItem(ItemType item)
{
	NodeType<ItemType>* location;
	location = new NodeType<ItemType>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}

template<class ItemType>
void LinkedList<ItemType>::DeleteItem(ItemType item)
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* tempLocation;

	if (item == listData->info)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (!(item == (location->next)->info))
			location = location->next;

		tempLocation = location->next;
		location->next = (location->next)->next;
	}

	delete tempLocation;
	length--;
}

template<class ItemType>
void LinkedList<ItemType>::ResetList()
{
	currentPos = listData;
}

template<class ItemType>
void LinkedList<ItemType>::GetNextItem(ItemType& item)
{
	item = currentPos->info;
	currentPos = currentPos->next;
}