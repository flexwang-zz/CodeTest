/*
n inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/
#include <stdio.h>
#include <vector>

using namespace std;

#define size 100

struct Node
{
	Node(int k) :key(k), left(NULL), right(NULL){}

	int key;
	Node *left, *right;
};

void post_trav(Node *root, vector<int> &v) {
	if (root->left)
		post_trav(root->left, v);

	if (root->right)
		post_trav(root->right, v);

	v.push_back(root->key);
}

int main()
{

	int n;

	scanf("%d", &n);

	Node* root = NULL;
	Node* last = root;
	Node* stack[size];
	int	sp = 0;

	for (int i = 0; i < 2*n; i++) {
		char cmd[20];

		scanf("%s", cmd);

		if (cmd[1] == 'u') {
			int key;

			scanf("%d", &key);
			if (!root) {
				root = new Node(key);
				last = root;
				
			}
			else if (!last->left) {
				last->left = new Node(key);
				last = last->left;
			}
			else {
				last->right = new Node(key);
				last = last->right;
			}
			stack[sp++] = last;
		}
		else {
			last = stack[--sp];
		}
	}

	vector<int> v;
	post_trav(root, v);

	for (int i = 0; i < n; i++) {
		if (i)	printf(" ");
		printf("%d", v[i]);
	}
	return 0;
}
