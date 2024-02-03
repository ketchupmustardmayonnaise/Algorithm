#include "DynamicAllocStackType.h"
#include <stdexcept>

template<class ItemType>
StackType<ItemType>::StackType()
{
	topPtr = nullptr;
}

template<class ItemType>
StackType<ItemType>::~StackType()
{
	NodeType* tempPtr;

	while (topPtr != nullptr)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
	if (IsFull())
		throw FullStack();

	NodeType* location;
	location = new NodeType<ItemType>;
	
	location->info = newItem;
	location->next = topPtr;
	topPtr = location;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	else
	{
		NodeType tempPtr;
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
	NodeType* location;
	try
	{
		// ���ο� Node�� �޴� ���� ������ => false
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		// Node�� ������ �ص� �� �޾��� �� => true
		return true;
	}
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	return (topPtr == nullptr);
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	else
		return topPtr->info;
}

int main()
{}