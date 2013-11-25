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

#include<stdio.h>
#include<vector>

using namespace std;

struct Node {
	int start1, end1;
	int start2, end2;
	Node(int s1, int e1, int s2, int e2) :
			start1(s1), end1(e1), start2(s2), end2(e2) {
	}
};

int main() {
	int n;
	int postorder[30];
	int inorder[30];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &inorder[i]);
	}

	vector<struct Node> curlayer;

	curlayer.push_back(Node(0, n - 1, 0, n - 1));

	bool firstprint = true;

	while (curlayer.size() > 0) {
		vector<struct Node> nextlayer;
		for (int i = 0; i < curlayer.size(); i++) {
			getchar();
			int start1 = curlayer[i].start1;
			int start2 = curlayer[i].start2;
			int end1 = curlayer[i].end1;
			int end2 = curlayer[i].end2;
#ifdef DEBUG
			printf("%d %d %d %d\n", start1, end1, start2, end2);
#endif
			if (firstprint) {
				firstprint = false;
			} else {
				printf(" ");
			}
			int root = postorder[end1];
			printf("%d", root);

			//find the index of root in inorder
			int rootindex;
			for (int j = start2; j <= end2; j++) {
				if (inorder[j] == root) {
					rootindex = j;
					break;
				}
			}

			int leftsize = rootindex - start2;
			int rightsize = end2 - rootindex;
#ifdef DEBUG
			printf("%d %d\n", leftsize, rightsize);
#endif
			if (leftsize > 0)
				nextlayer.push_back(
						Node(start1, start1 + leftsize - 1, start2,
								rootindex - 1));
			if (rightsize > 0)
				nextlayer.push_back(
						Node(start1 + leftsize, end1 - 1, rootindex + 1, end2));
		}
		curlayer = nextlayer;
	}

	return 0;
}

