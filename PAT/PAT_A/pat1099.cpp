
/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.


Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void inorder(const vector<pair<int,int>> &G, int root, vector<int>& v, vector<int>& tree, int &i) {
    if (root < 0) return;
    inorder(G, G[root].first, v, tree, i);
    tree[root] = v[i++];
    inorder(G, G[root].second, v, tree, i);
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> G(n);
    vector<int> v(n), tree(n);
    for (int i=0; i<n; i++)
        cin >> G[i].first >> G[i].second;
    for (int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int i=0;
    inorder(G, 0, v, tree, i);

    vector<int> level_order;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int p =que.front();
        que.pop();
        level_order.push_back(tree[p]);
        if (G[p].first >= 0) que.push(G[p].first);
        if (G[p].second >= 0) que.push(G[p].second);
    }
    for (int i=0; i<level_order.size(); i++)
        printf("%d%c", level_order[i], i==level_order.size()-1?'\n':' ');
    return 0;
}