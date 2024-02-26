#pragma once

template<class ItemType>
struct HeapType
{
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	ItemType* elements; // 배열 동적 할당
	int numElements;
};