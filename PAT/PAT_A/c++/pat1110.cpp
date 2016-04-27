/*
Given a tree, you are supposed to tell if it is a complete binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each case, print in one line "YES" and the index of the last node if the tree is a complete binary tree, or "NO" and the index of the root if not. There must be exactly one space separating the word and the number.

Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1
*/

#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int n, root;
pair<int,int> nodes[21];
bool flag[21];

int bfs()
{
    queue<int> que;
    que.push(root);
    bool missing = false;
    int p;
    while (!que.empty()) {
        p = que.front();
        que.pop();
        if (missing && nodes[p].first>=0) return -1;
        if (nodes[p].first >= 0) que.push(nodes[p].first);
        else missing = true;
        if (missing && nodes[p].second>=0) return -1;
        if (nodes[p].second >= 0) que.push(nodes[p].second);
        else missing = true;
    }
    return p;
}

int main()
{
    cin >> n;

    for (int i=0; i<n; ++i) {
        string a, b;
        cin >> a >> b;
        nodes[i].first = a=="-"?-1:atoi(a.c_str());
        nodes[i].second = b=="-"?-1:atoi(b.c_str());
        if (nodes[i].first >= 0) flag[nodes[i].first] = true;
        if (nodes[i].second >= 0) flag[nodes[i].second] = true;
    }

    root = -1;
    for (int i=0; i<n; ++i)
        if (!flag[i]) root = i;
    int res = bfs();
    if (res < 0) printf("NO %d", root);
    else printf("YES %d", res);
    return 0;
}