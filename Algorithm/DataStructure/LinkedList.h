#pragma once
#include "NodeType.h"

template<class ItemType>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void MakeEmpty();
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	NodeType<ItemType>* listData; // �� ù ��° ������
	int length;
	NodeType<ItemType>* currentPos;
};