#include "DynamicAllocStackType.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<class ItemType>
StackType<ItemType>::StackType()
{
	topPtr = nullptr;
}

template<class ItemType>
StackType<ItemType>::~StackType()
{
	NodeType<ItemType>* tempPtr;

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

	NodeType<ItemType>* location;
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
		NodeType<ItemType>* tempPtr;
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
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
{
	StackType<int> stack;
	stack.Push(3);
	stack.Push(5);

	cout << stack.Top() << endl;
	stack.Pop();
	cout << stack.Top() << endl;
	stack.Pop();
}