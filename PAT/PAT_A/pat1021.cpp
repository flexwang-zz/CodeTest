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

#include<stdio.h>
#include<vector>

using namespace std;

struct Node {
	vector<int> adjacent;
};

struct Path {
	int from, to;
	Path(int f, int t) :
			from(f), to(t) {
	}
};

struct Node nodes[10001];
bool search(int rootid, bool known[], int curdepth, int &maxdepth, int &nknown,
		int fatherid);
int findroot(int id, int root[]);

int main() {
	int n;
	scanf("%d", &n);

	bool known[100001];
	vector<Path> paths;

	for (int i = 1; i <= n - 1; i++) {
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		nodes[a1].adjacent.push_back(a2);
		nodes[a2].adjacent.push_back(a1);
		paths.push_back(Path(a1, a2));
	}

	int maxdepth = -1;
	vector<int> deepestroot;
	int nknown;

	for (int i = 1; i <= n; i++) {
		int depth = -1;
		nknown = 0;
		for (int j = 1; j <= n; j++) {
			known[j] = false;
		}

		if (search(i, known, 1, depth, nknown, -1)) {
			if (maxdepth < depth) {
				maxdepth = depth;
				deepestroot.clear();
				deepestroot.push_back(i);
//        deepestropot
			} else if (maxdepth == depth) {
				deepestroot.push_back(i);
			}
//      printf("%d %d\n", i, depth);
		} else {
			break;
//      printf("sorry\n");
		}
		if (nknown < n) {
			break;
		}
//    printf("known:%d\n", nknown);
	}

	if (nknown == n) {
		for (int i = 0; i < deepestroot.size(); i++) {
			printf("%d\n", deepestroot[i]);
		}
	} else {
		int ncomponents = n;
		int root[100001];
		for (int i = 1; i <= n; i++) {
			root[i] = i;
		}

		for (int i = 0; i < paths.size(); i++) {
			int a = paths[i].from;
			int b = paths[i].to;

			int root1 = findroot(a, root);
			int root2 = findroot(b, root);

			if (root1 != root2) {
				root[root1] = root2;
				ncomponents--;
			}
		}
		printf("Error: %d components", ncomponents);
	}
//  while(1);
	return 0;
}

bool search(int rootid, bool known[], int curdepth, int &maxdepth, int& nknown,
		int fatherid) {
	if (known[rootid]) {
		return false;
	}

	known[rootid] = true;
	curdepth++;
	nknown++;
	if (curdepth > maxdepth) {
		maxdepth = curdepth;
	}

	for (int i = 0; i < nodes[rootid].adjacent.size(); i++) {
		int id = nodes[rootid].adjacent[i];
		if (id == fatherid) {
			continue;
		}
//    printf("%d ", id);
		if (!(search(id, known, curdepth, maxdepth, nknown, rootid))) {
			return false;
		}
	}
//  printf("\n");
	return true;
}

int findroot(int id, int root[]) {
	int r;
	while ((r = root[id]) != id) {
		root[id] = root[r];
		id = r;
	}

	return r;
}

