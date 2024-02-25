#pragma once
#include "NodeType.h"

template<class ItemType>
class QueType
{
public:
	QueType();
	~QueType();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType item);
	void Dequeue(ItemType& item);
	void MakeEmpty();
private:
	NodeType<ItemType>* qFront;
	NodeType<ItemType>* qRear;
};