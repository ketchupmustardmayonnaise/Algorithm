#pragma once

template<class ItemType>
class QueType
{
public:
	QueType();
	QueType(int max);
	~QueType();

	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType item);
	void Dequeue(ItemType& item);
private:
	int front;
	int rear;
	int maxQue;
	ItemType* items;
};