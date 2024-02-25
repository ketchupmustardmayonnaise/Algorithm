#include "DynamicAllocQueueType.h"
#include <iostream>
#include <stdexcept>

template<class ItemType>
QueType<ItemType>::QueType()
{
	qFront = nullptr;
	qRear = nullptr;
}

template<class ItemType>
QueType<ItemType>::~QueType()
{
	ItemType tempItem;
	while (!IsEmpty()) Dequeue(tempItem);
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
	NodeType<ItemType>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == nullptr) qRear = nullptr;
	delete tempPtr;
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType item)
{
	NodeType<ItemType>* ptr;

	ptr = new NodeType<ItemType>;
	ptr->info = item;
	ptr->next = nullptr;

	if (qRear == nullptr) qFront = ptr; // queue가 비어 있다면
	else qRear->next = ptr;

	qRear = ptr;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
	return (qFront == nullptr);
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
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

int main()
{
	QueType<int> queue;
	queue.Enqueue(5);
	queue.Enqueue(7);
	int item;
	queue.Dequeue(item);
	std::cout << item << '\n';
	queue.Dequeue(item);
	std::cout << item << '\n';
}