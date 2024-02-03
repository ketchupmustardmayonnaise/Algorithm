#pragma once
#define MAX_ITEMS 10000

class FullStack {};
class EmptyStack {};

template<class ItemType>
class StackType
{
public:
	StackType(); // »ý¼ºÀÚ
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(ItemType item);
	void Pop(ItemType& item);
	ItemType Top();
private:
	int top;
	ItemType items[MAX_ITEMS];
};