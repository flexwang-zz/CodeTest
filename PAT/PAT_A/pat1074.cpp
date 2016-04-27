/*
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1->2->3->4->5->6, if K = 3, then you must output 3->2->1->6->5->4; if K = 4, you must output 4->2->1->5->6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

*/
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int value;
	int next;

	node(){}
	node(int n, int v):next(n), value(v){}
};

void reverse(vector<int>&, int, int);

int main()
{
	int head, nnode, k;

	scanf("%d %d %d", &head, &nnode, &k);

	vector<node> nodes(100001);
	for (int i=0; i<nnode; i++) {
		int key, value, next;

		scanf("%d %d %d", &key, &value, &next);

		nodes[key].value = value;
		nodes[key].next = next;
	}

	vector<int> keys;

	int p = head;

	while (p >= 0) {
		keys.push_back(p);
		p = nodes[p].next;
	}

	int size = keys.size();

	int nrun = size/k;

	for (int i=0; i<nrun; i++) {
		reverse(keys, k*i, k*(i+1)-1);
	}

	for (int i=0; i<size; i++) {
		printf("%05d %d ", keys[i], nodes[keys[i]].value);

		if (i == (size-1)) {
			printf("-1\n");
		}
		else {
			printf("%05d\n", keys[i+1]);
		}
	}

	return 0;
}

void reverse(vector<int>&keys, int start, int end) {
	
	while (start < end) {
		int temp = keys[start];
		keys[start] = keys[end];
		keys[end] = temp;

		start++;
		end--;
	}
}