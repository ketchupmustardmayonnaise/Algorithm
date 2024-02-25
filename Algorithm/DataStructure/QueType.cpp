#include "QueType.h"

template<class ItemType>
QueType<ItemType>::QueType(int max)
{
	maxQue = max + 1;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new ItemType[maxQue]; // 동적 할당
}

template<class ItemType>
QueType<ItemType>::~QueType()
{
	delete[] items;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
	return (rear == front);
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
{
	return ((rear + 1) % maxQue == front);
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType item)
{
	rear = (rear + 1) % maxQue;
	items[rear] = item;
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
	front = (front + 1) % maxQue;
	item = items[front];
}

int main()
{
}