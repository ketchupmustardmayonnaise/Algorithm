#pragma once
#include "NodeType.h"

class FullStack {};
class EmptyStack {};

template<class ItemType>
class StackType
{
public:
	StackType();
	~StackType();
	bool IsEmpty() const;
	bool IsFull() const;
	void Pop();
	void Push(ItemType newItem);
	ItemType Top();
private:
	NodeType<ItemType>* topPtr;
};