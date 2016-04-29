/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:

For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n

where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int value;
    Node *left, *right;
    Node(){}
    Node(int v):value(v), left(NULL), right(NULL){}
};

struct BST{
    BST():root(NULL){}
    Node *root;
    void insert(int n) {
        f(root, n);
    }
    void f(Node*& node, int n) {
        if (!node) node = new Node(n);
        else if (n <= node->value) f(node->left, n);
        else f(node->right, n);
    }
    pair<int,int> g() {
        vector<int> cnt;
        vector<Node*> l = {root};
        while (!l.empty()) {
            cnt.push_back(l.size());
            vector<Node*> next;
            for (auto p:l) {
                if (p->left) next.push_back(p->left);
                if (p->right) next.push_back(p->right);
            }
            l = next;
        }
        return {cnt.back(), cnt[cnt.size()-2]};
    }
};

int main()
{
    BST bst;
    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        int x;
        cin >> x;
        bst.insert(x);
    }
    auto p = bst.g();
    printf("%d + %d = %d", p.first, p.second, p.first+p.second);
    return 0;
}