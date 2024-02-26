#include "HeapType.h"
#include <algorithm>
using namespace std;

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
	// 전제조건: root노드가 Heap의 특성을 위배함.
	int maxChild;
	int rightChild;
	int leftChild;
	
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom) // 자식이 하나일 경우
			maxChild = leftChild;
		else // 자식이 두 개인 경우
		{
			// maxChild: 두 자식 중 큰 자식을 택함.
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;

			// root보다 큰 값을 갖는 자식과, root를 swap하고
			// 해당 자식을 ReheapDown함으로써 원위치로 보냄.
			if (elements[root] < elements[maxChild])
			{
				swap(elements[root], elements[maxChild]);
				ReheapDown(maxChild, bottom);
			}
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
	// 전제조건: 마지막 레벨의 가장 오른쪽 노드가
	// Heap의 특성을 위배함.
	int parent;

	if (bottom > root) // tree가 비어 있지 않고 존재함
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			// parent와 rightmost bottom 값을 바꾸고, 다시 ReheapUp 진행
			swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}