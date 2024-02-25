#include "StackType.h"
#include <iostream>
using namespace std;

template<class ItemType>
StackType<ItemType>::StackType()
{
	top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	if (top < 0) return true;
	else return false;
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
	if (top == MAX_ITEMS) return true;
	else return false;
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
	if (IsEmpty())
		throw EmptyStack();
	item = items[top];
	top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
	return items[top];
}

int main()
{
	StackType<int> items;
	
	items.Push(3);
	items.Push(5);

	int value;
	items.Pop(value);
	cout << value << endl;
	items.Pop(value);
	cout << value << endl;
}