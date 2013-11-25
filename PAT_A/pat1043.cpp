/*
 ﻿A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.
 Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
 Sample Input 1:
 7
 8 6 5 7 10 8 11

 Sample Output 1:
 YES
 5 7 6 8 11 10 8

 Sample Input 2:
 7
 8 10 11 8 6 7 5

 Sample Output 2:
 YES
 11 8 10 7 5 6 8

 Sample Input 3:
 7
 8 6 8 5 10 9 11

 Sample Output 3:
 NO


 */

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stdlib.h>

using namespace std;

struct Node {
	int val;
	Node* right, *left;

	Node(int v) :
			val(v), right(NULL), left(NULL) {
	}
};

void Itoa(int v, char *ch, int radix) {
	int index = 0;

	do {
		ch[index++] = v % 10 + '0';
		v /= 10;
	} while (v > 0);
	ch[index] = '\0';
	for (int i = 0; i < index / 2; i++) {
		char tmp = ch[i];
		ch[i] = ch[index - 1 - i];
		ch[index - 1 - i] = tmp;
	}
}

class Tree {
public:
	Node *head;
	Node *head2;

	Tree() :
			head(NULL), head2(NULL) {
	}

	void insert(int val) {
		insert(val, head);
	}

	void insert(int val, Node*&t) {
		if (!t) {
			t = new Node(val);
		} else {
			if (val < t->val) {
				insert(val, t->left);
			} else {
				insert(val, t->right);
			}

		}
	}

	vector<int> preorder() {
		vector<int> v;
		preorder(v, head);

		return v;
	}

	vector<int> preorder2() {
		vector<int> v;
		preorder2(v, head);

		return v;
	}

	void postorder2() {
		bool space = false;
		postorder2(head, space);
	}

	void postorder2(Node*n, bool &space) {
		if (n) {
			postorder2(n->right, space);
			postorder2(n->left, space);

			if (space) {
				cout << " ";
			} else {
				space = true;
			}
			cout << n->val;
		}
	}

	void postorder() {
		bool space = false;
		postorder(head, space);
	}

	void postorder(Node*n, bool& space) {
		if (n) {
			postorder(n->left, space);
			postorder(n->right, space);
			if (space) {
				cout << " ";
			} else {
				space = true;
			}
			cout << n->val;
		}
	}

	void preorder(vector<int> &v, Node*n) {
		if (n) {
			v.push_back(n->val);
			preorder(v, n->left);
			preorder(v, n->right);
		}
	}

	void preorder2(vector<int> &v, Node*n) {
		if (n) {
			v.push_back(n->val);
			preorder2(v, n->right);
			preorder2(v, n->left);

		}
	}

};

int main() {
	int n;
	Tree tree;
	cin >> n;

	vector<int> v;
	int d;
	for (int i = 0; i < n; i++) {
		cin >> d;
		v.push_back(d);
		tree.insert(d);
	}

//  cout<<tree.preorder()<<endl<<tree.preorderimg()<<endl;
	if (v == tree.preorder()) {
		printf("YES\n");

		tree.postorder();
	} else if (v == tree.preorder2()) {
		printf("YES\n");
		tree.postorder2();
	} else {
		printf("NO\n");
	}

//  while(1);
	return 0;
}

