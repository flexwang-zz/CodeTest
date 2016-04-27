/*
﻿A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02

Sample Output
0 1
*/
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n+1);
	for (int i=0; i<m; ++i) {
		int f, k;
		cin >> f >> k;
		G[f].resize(k);
		for (int j=0; j<k; ++j)
			cin >> G[f][j];
	}
	vector<int> res;
	vector<int> level = {1};
	while (level.size()!=0) {
		vector<int> next;
		int cnt = 0;
		for (auto &x : level)
			if (G[x].size())
				for (auto &y : G[x]) next.push_back(y);
			else ++cnt;
		res.push_back(cnt);
		level = next;
	}
	for (int i=0; i<res.size(); ++i)
		printf("%d%c", res[i], i==res.size()-1?'\n':' ');
	return 0;
}