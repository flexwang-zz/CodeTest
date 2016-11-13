/*
 ﻿Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
 Input Specification:
 Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
 Sample Input:
 7
 2 3 1 5 7 6 4
 1 2 3 4 5 6 7

 Sample Output:
 4 1 6 3 5 7 2

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v), left(NULL), right(NULL){}
};

int findRootIndex(vector<int>& v, int begin , int end , int root_val){
	return std::find(v.begin()+begin, v.begin()+end+1, root_val)-v.begin();
} 

Node* buildTree(const vector<int> &v1, int &idx , const vector<int> &v2 ,int s , int t){
	if (s > t) return NULL;
	Node* root = new Node(v1[idx--]);
	int k = findRootIndex( v2 , s, t , root->val);
	root->right = buildTree(v1, idx, v2, k+1, t);
	root->left = buildTree(v1, idx, v2, s, k-1);
	return root;
}
 
vector<int> get_bfs(Node* root) {
	vector<int> rt;
	if (!root) return rt;
	queue<Node*> que;
	que.push(root);
	while (!que.empty()) {
		Node *p = que.front();
		que.pop();
		rt.push_back(p->val);
		if (p->left) que.push(p->left);
		if (p->right) que.push(p->right);
	}
	return rt;
}
 
int main()
{
	int k;
	cin>>k;
	vector<int> post(k), in(k);
	for (int i = 0; i < k; ++i)
		cin>>post[i];
	for (int i = 0; i < k; ++i)
		cin>>in[i];
	int idx = k-1;
	Node* root = buildTree (post , idx, in , 0 , k-1);
	vector<int> rt = get_bfs(root);
	for (int i=0; i<k; ++i)
		printf("%d%c", rt[i], i==k-1?'\n':' ');
	return 0;
}
