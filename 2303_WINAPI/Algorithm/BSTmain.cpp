#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#include "BST.h"

// BST (Binary Search Tree) => 이진 탐색 트리

int main()
{
	BST bst;
	bst.Insert(50);
	bst.Insert(2);
	bst.Insert(83);
	bst.Insert(36);
	bst.Insert(5);
	bst.Insert(8);
	bst.Insert(375);
	bst.Insert(89);
	bst.Insert(3);
	bst.Insert(56);

	bst.PrintTree(bst._root);

	Node* node1 = bst.Min(bst._root);
	Node* node2 = bst.Max(bst._root);
	Node* node3 = bst.Previous(bst._root);
	Node* node4 = bst.Next(bst._root);
	Node* node5 = bst.Search(bst._root, 8);

	return 0;
}