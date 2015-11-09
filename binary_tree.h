#pragma once
#include <iostream>
using namespace std;
//二叉树
class BinaryTree
{
protected:
	struct Node;
public:
	BinaryTree():m_root(NULL)
	{
	}

	void display()
	{
		if(NULL != m_root)
		{
			inorder_traversal(m_root);
		}
	}


private:
	BinaryTree(const BinaryTree& src);
	BinaryTree& operator=(const BinaryTree& src);

	void preorder_traversal(struct Node* root)
	{
		if(NULL == root)
			return;
		if(NULL != root->left)
			preorder_traversal(root->left);
		cout<<root->value<<endl;
		if(NULL != root->right)
			preorder_traversal(root->right);

	}
	void inorder_traversal(struct Node* root)
	{
		if(NULL == root)
			return;
		cout<<root->value<<endl;
		if(NULL != root->left)
			inorder_traversal(root->left);
		if(NULL != root->right)
			inorder_traversal(root->right);
	}
	void postorder_traversal(struct Node* root)
	{
		if(NULL == root)
			return;
		if(NULL != root->left)
			postorder_traversal(root->left);
		if(NULL != root->right)
			postorder_traversal(root->right);
		cout<<root->value<<endl;

	}
protected:
	struct Node
	{
		int value;
		Node* parent;
		Node* left;
		Node* right;
		Node():parent(NULL),left(NULL),right(NULL)
		{
			value = 0;
		}
		Node(int val):parent(NULL),left(NULL),right(NULL)
		{
			value = val;
		}
	};
protected:
	struct Node* m_root;
};
//二叉查找树
class BinarySearchTree:public BinaryTree
{
public:
	BinarySearchTree():BinaryTree()
	{
	}
	//找到返回1，失败返回0
	int search(int value)
	{
		struct Node* parent = find_parent(value);
		if(parent->value > value)
		{
			if(parent->left != NULL && parent->left->value == value)
				return 1;
		}
		if(parent->value < value)
		{
			if(parent->right != NULL && parent->right->value == value)
				return 1;
		}
	}

	void insert(int value)
	{
		struct Node* parent = find_parent(value);
		if(parent == NULL && m_root == NULL)
		{
			m_root = new Node(value);
			return;
		}
		if(parent == NULL && m_root != NULL && m_root->value == value)
			return;
		if(parent->value > value)
		{
			if(parent->left != NULL && parent->left->value == value)
				return;
			if(parent->left == NULL)
			{
				parent->left = new Node(value);
				return;
			}
		}
		if(parent->value < value)
		{
			if(parent->right != NULL && parent->right->value == value)
				return;
			if(parent->right == NULL)
			{
				parent->right = new Node(value);
				return;
			}
		}
	}
private:
	BinarySearchTree(const BinarySearchTree& src);
	BinarySearchTree& operator=(const BinarySearchTree& src);
	//找到value的父结点，(value不一定已经在树中)
	//返回NULL,代表为空树，或者树根即value
	struct Node* find_parent(int value)
	{
		if(NULL == m_root || value == m_root->value)
			return NULL;
		struct Node* parent = m_root;
		struct Node* son = NULL;

		if(parent->value > value)
			son = parent->left;
		else if (parent->value < value)
			son = parent->right;
		else
			;
		while(son != NULL)
		{
			if(son->value == value)
				break;
			else if(son->value > value)
			{
				parent = son;
				son = son->left;
			}
			else if(son->value < value)
			{
				parent = son;
				son = son->right;
			}
		}
		return parent;
	}
};
