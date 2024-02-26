#pragma once
#include "QueType.h"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template<class ItemType>
struct TreeNode {
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

template<class ItemType>
class TreeType {
public:
	TreeType();
	~TreeType();
	void MakeEmpty(TreeNode<ItemType>*& tree);
	bool IsEmpty() const;
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(TreeNode<ItemType>*& tree);
	void ResetTree(OrderType order);
	void GetNextItem(ItemType& item, OrderType order, bool& finished);
	void PrintTree(TreeNode<ItemType>* tree) const;
	void Print() const;
private:
	TreeNode<ItemType>* root;
	QueType<ItemType> preQue;
	QueType<ItemType> inQue;
	QueType<ItemType> postQue;
};