#include "HeapType.h"
#include <algorithm>
using namespace std;

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
	// ��������: root��尡 Heap�� Ư���� ������.
	int maxChild;
	int rightChild;
	int leftChild;
	
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom) // �ڽ��� �ϳ��� ���
			maxChild = leftChild;
		else // �ڽ��� �� ���� ���
		{
			// maxChild: �� �ڽ� �� ū �ڽ��� ����.
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;

			// root���� ū ���� ���� �ڽİ�, root�� swap�ϰ�
			// �ش� �ڽ��� ReheapDown�����ν� ����ġ�� ����.
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
	// ��������: ������ ������ ���� ������ ��尡
	// Heap�� Ư���� ������.
	int parent;

	if (bottom > root) // tree�� ��� ���� �ʰ� ������
	{
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom])
		{
			// parent�� rightmost bottom ���� �ٲٰ�, �ٽ� ReheapUp ����
			swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}