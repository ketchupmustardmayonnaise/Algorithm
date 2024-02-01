#include "StackType.h"
#include <iostream>

template<class ItemType>
StackType<ItemType>::StackType()
{
	top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{

}

template<class ItemType>
void StackType<ItemType>::Push(ItemType item)
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = item;
}

template<class ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{

}