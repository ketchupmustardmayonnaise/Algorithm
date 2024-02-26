#include "BinarySearchTree.h"
#include <iostream>

template<class ItemType>
TreeType<ItemType>::TreeType()
{
	root = nullptr;
}

template<class ItemType>
TreeType<ItemType>::~TreeType()
{
	MakeEmpty(root);
}

template<class ItemType>
void TreeType<ItemType>::MakeEmpty(TreeNode<ItemType>*& tree)
{
	if (tree != nullptr)
	{
		MakeEmpty(tree->left);
		MakeEmpty(tree->right);
		delete tree;
	}
}

template<class ItemType>
bool TreeType<ItemType>::IsFull() const
{
	ItemType* location;
	try
	{
		location = new ItemType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

template<class ItemType>
bool TreeType<ItemType>::IsEmpty() const
{
	return root == nullptr;
}

template<class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
{
	// ����Լ��� �ݺ������ν� root�� ���� ����� ������ �L.
	if (tree == nullptr) return 0;
	else return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template<class ItemType>
int TreeType<ItemType>::LengthIs() const
{
	return CountNodes(root);
}

template<class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
{
	if (tree == nullptr) found = false;
	else if (item < tree->info) Retrieve(tree->left, item, found);
	else if (item > tree->info) Retrieve(tree->right, item, found);
	else
	{
		item = tree->info;
		found = true;
	}
}

template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	Retrieve(root, item, found);
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
{
	if (tree == nullptr)
	{ // tree�� ����.
		tree = new TreeNode<ItemType>;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->info = item;
	}
	else if (item < tree->info) Insert(tree->left, item);
	else Insert(tree->right, item);
}

template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
	Insert(root, item);
}

template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
{
	while (tree->right != nullptr) tree = tree->right;
	data = tree->info;
}

template<class ItemType>
void TreeType<ItemType>::DeleteItem(TreeNode<ItemType>*& tree)
{
	TreeNode* tempPtr = tree;
	if (tree->left == nullptr) // ������ �ڽ��� ���
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == nullptr) // ���� �ڽ��� ���
	{
		tree = tree->left;
		delete tempPtr;
	}
	else // �ڽ� �� �� ��� ���� ��� -> Predecessor�� ã�Ƽ� �̸� ��ü��.
	{
		ItemType data;
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);
	}
}

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
{
	// item�̶�� ���� ���� ��带 ã�� ������.
	if (item < tree->info) Delete(tree->left, item);
	else if (item > tree->info) Delete(tree->right, item);
	else DeleteItem(tree); // Node found
}

template<class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueType<ItemType>& Que)
{
	if (tree != nullptr)
	{
		InOrder(tree->left, Que);
		Que.Enqueue(tree->info);
		InOrder(tree->right, Que);
	}
}

template<class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType<ItemType>& Que)
{
	if (tree != nullptr)
	{
		Que.Enqueue(tree->info);
		PreOrder(tree->left, Que);
		PreOrder(tree->right, Que);
	}
}

template<class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType<ItemType>& Que)
{
	if (tree != nullptr)
	{
		PostOrder(tree->left, Que);
		PostOrder(tree->right, Que);
		Que.Enqueue(tree->info);
	}
}

template<class ItemType>
void TreeType<ItemType>::Print() const
{
	PrintTree(root);
}

template<class ItemType>
void TreeType<ItemType>::PrintTree(TreeNode<ItemType>* tree) const
{
	if (tree != nullptr)
	{
		PrintTree(tree->left);
		std::cout << tree->info << '\n';
		PrintTree(tree->right);
	}
}

template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
{
	switch (order)
	{
	case PRE_ORDER: PreOrder(root, preQue);
		break;
	case IN_ORDER: InOrder(root, inQue);
		break;
	case POST_ORDER: PostOrder(root, postQue);
		break;
	}
}

template<class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished)
{
	finished = false;
	switch (order)
	{
	case PRE_ORDER: preQue.Dequeue(item);
		if (preQue.IsEmpty()) finished = true;
		break;
	case IN_ORDER: inQue.Dequeue(item);
		if (inQue.IsEmpty()) finished = true;
		break;
	case POST_ORDER: postQue.Dequeue(item);
		if (postQue.IsEmpty()) finished = true;
		break;
	}
}

template<class ItemType>
void FindNode(TreeNode<ItemType>* tree, ItemType item, TreeNode<ItemType>*& nodePtr, TreeNode<ItemType>*& parentPtr)
{
	nodePtr = tree;
	parentPtr = nullptr;
	bool found = false;

	while (nodePtr != nullptr && !found)
	{
		if (item < nodePtr->info)
		{
			parentPtr = nodePtr;
			nodePtr = nodePtr->left;
		}
		else if (item > nodePtr->info)
		{
			parentPtr = nodePtr;
			nodePtr = nodePtr->right;
		}
		else found = true;
	}
}

int main()
{
	TreeType<int> tree;
	tree.InsertItem(5);
	tree.InsertItem(3);
	tree.InsertItem(7);
	tree.ResetTree(IN_ORDER);
	tree.Print();
}