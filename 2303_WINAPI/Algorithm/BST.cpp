#include <iostream>

using namespace std;

#include "BST.h"

BST::BST()
{
}

BST::~BST()
{
}

void BST::Insert(int key)
{
	Node* newNode = new Node(key);

	// 트리의 첫 생성
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (true)
	{
		if (node == nullptr)
			break;

		if (key == node->key)
		{
			node->data = newNode->data;
			return;
		}

		parent = node;
		if (key < node->key)
		{
			node = node->left;
		}
		else if (key > node->key)
		{
			node = node->right;
		}
	}

	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else if (key > parent->key)
		parent->right = newNode;
}

void BST::PrintTree(Node* node)
{
	if (node == nullptr)
		return;

	PrintTree(node->left);
	cout << node->key << endl;
	PrintTree(node->right);
}

Node* BST::Search(Node* node, int key)
{
	if (node == nullptr)
		return nullptr;

	if (key == node->key)
		return node;

	if (key < node->key)
		Search(node->left, key);
	else
		Search(node->right, key);
}

Node* BST::Min(Node* node)
{
	if (node->left == nullptr)
		return node;

	Min(node->left);
}

Node* BST::Max(Node* node)
{
	if (node->right == nullptr)
		return node;

	Max(node->right);
}

Node* BST::Previous(Node* node)
{
	return Max(node->left);
}

Node* BST::Next(Node* node)
{
	return Min(node->right);
}
