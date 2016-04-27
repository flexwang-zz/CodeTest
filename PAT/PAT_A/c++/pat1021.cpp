/*
 ﻿A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
 Output Specification:
 For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.
 Sample Input 1:
 5
 1 2
 1 3
 1 4
 2 5
 Sample Output 1:
 3
 4
 5
 Sample Input 2:
 5
 1 3
 1 4
 2 5
 3 4
 Sample Output 2:
 Error: 2 components
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

inline void add_edge(int a, int b, vector<vector<int>>&G) {
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
}

bool dfs(int id, int p, vector<vector<int>> &G, vector<bool>& visited) {
    if (visited[id]) return false;
    visited[id] = true;
    bool flag = true;
    for (int i=0; i<G[id].size(); i++) {
        if (G[id][i] == p) continue;
        flag &= dfs(G[id][i], id, G, visited);
    }
    return flag;
}

int get_height(int root, vector<vector<int>> &G) {
    vector<pair<int,int>> level = {{root,-1}};
    int h = 1;
    while (level.size() != 0) {
        vector<pair<int,int>> temp;
        for (int i=0; i<level.size(); i++) {
            int cur = level[i].first;
            int p = level[i].second;
            for (int j=0; j<G[cur].size(); j++) {
                int v = G[cur][j];
                if (v == p) continue;
                temp.push_back(make_pair(v, cur));
            }
        }
        level = temp;
        h++;
    }
    return h;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, G);
    }
    vector<bool> visited(n, false);
    int k = 0;
    bool is_tree = true;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            ++k;
            is_tree &= dfs(i, -1, G, visited);
        }
    }
    if (!is_tree || k > 1) {
        cout << "Error: "<< k << " components" << endl;
        return 0;
    }
    int height = 0;
    vector<int> ans;
    for (int i=0; i<n; i++) {
        int h;
        if ((h=get_height(i, G)) > height) {
            ans = {i};
            height = h;
        }
        else if (h == height)
            ans.push_back(i);
    }
    
    for (int i=0; i<ans.size(); i++) 
        cout << ++ans[i] << endl;
    return 0;
    
}
