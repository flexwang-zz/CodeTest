/*
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <string>
#include <queue>

using namespace std;

void inorder(int root, vector<pair<int,int>>&G, vector<int> &result) {
    if (root < 0) return;
    inorder(G[root].first, G, result);
    result.push_back(root);
    inorder(G[root].second, G, result);
}

vector<int> level_order(int root, vector<pair<int,int>>&G) {
    vector<int> result;
    queue<int> que;
    que.push(root);
    while (!que.empty()){
        int p = que.front();
        que.pop();
        result.push_back(p);
        if (G[p].first >= 0) que.push(G[p].first);
        if (G[p].second >= 0) que.push(G[p].second);
    }
    return result;
}

inline void print_vector(const vector<int>& v){
    for (int i=0; i<v.size(); ++i)
        printf("%d%c", v[i], i==v.size()-1?'\n':' ');
}
int main()
{
    int n;
    cin >> n;
    unordered_set<int> us;
    for (int i=0; i<n; i++)
        us.insert(i);
    vector<pair<int,int>> G(n);
    for (int i=0; i<n; ++i) {
        string id;
        cin >> id;
        if (id[0] == '-') G[i].second = -1;
        else {
            G[i].second = id[0]-'0';
            us.erase(id[0]-'0');
        }
        cin >> id;
        if (id[0] == '-') G[i].first = -1;
        else {
            G[i].first = id[0]-'0';
            us.erase(id[0]-'0');
        }
    }
    int root = *us.begin();
    vector<int> ino, lo;
    inorder(root, G, ino);
    lo = level_order(root, G);
    print_vector(lo);
    print_vector(ino);
    return 0;
}