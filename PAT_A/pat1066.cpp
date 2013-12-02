/*
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/
#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	int height;

	TreeNode(int v):val(v), height(0), left(NULL), right(NULL){}
};

int height(TreeNode*node)
{
	return node?node->height:-1;
}

class AVLTree
{
public:
	TreeNode *head;

	AVLTree(): head(NULL){}

	void insert(int val)
	{
		insert(val, head);
	}

	void print() const
	{
		print(head, 0);
	}

	void print(TreeNode* node, int level) const
	{
		if( node)
		{
			printf("%d %d %d\n", node->val, level, node->height);

			print(node->left, level+1);
			print(node->right, level+1);
		}
	}

	void insert(int val, TreeNode*&head)
	{
		if( !head )
		{
			head = new TreeNode(val);
		}
		else 
		{
			if( val < head->val)
			{
				insert(val, head->left);
				
				if( (height(head->left) - height(head->right)) == 2)
				{
					if( val < head->left->val)
					{
						TreeNode* k2 = head->left;
						head->left = k2->right;

						head->height = max(height(head->right), height(head->left))+1;
						k2->right = head;
						head = k2;
					}
					else
					{
						TreeNode* k2 = head->left;
						TreeNode* k3 = k2->right;

						head->left = k3->right;
						k2->right = k3->left;

						k3->left = k2;
						k3->right = head;

						head->height = max(height(head->right), height(head->left))+1;
						k2->height = max(height(k2->right), height(k2->left)) + 1;

						head = k3;
					}
				}
			}
			else if( val > head->val)
			{
				insert(val, head->right);

				if( (height(head->right) - height(head->left)) == 2)
				{
					if( val > head->right->val)
					{
						TreeNode* k2 = head->right;
						head->right = k2->left;
						head->height = max(height(head->left), height(head->right))+1;
						
						k2->left = head;
						head = k2;
					}
					else
					{
							TreeNode* k2 = head->right;
							TreeNode* k3 = k2->left;

							head->right = k3->left;
							k2->left = k3->right;

							k3->right = k2;
							k3->left = head;

							head->height = max(height(head->right), height(head->left))+1;
							k2->height = max(height(k2->right), height(k2->left)) + 1;

							head = k3;
					}
				}

			}
		}
		head->height = max(height(head->left), height(head->right)) + 1;
	}

};

int main()
{
	int nnode;
	AVLTree tree;

	scanf("%d", &nnode);

	for( int i=0; i<nnode; i++)
	{
		int val;
		scanf("%d", &val);
		tree.insert(val);
	}

	printf("%d", tree.head->val);

	return 0;
}