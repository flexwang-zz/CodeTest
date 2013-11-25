/*
 ﻿One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threthold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:
 Name1 Name2 Time
 where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
 Output Specification:
 For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
 Sample Input 1:
 8 59
 AAA BBB 10
 BBB AAA 20
 AAA CCC 40
 DDD EEE 5
 EEE DDD 70
 FFF GGG 30
 GGG HHH 20
 HHH FFF 10

 Sample Output 1:
 2
 AAA 3
 GGG 3

 Sample Input 2:
 8 70
 AAA BBB 10
 BBB AAA 20
 AAA CCC 40
 DDD EEE 5
 EEE DDD 70
 FFF GGG 30
 GGG HHH 20
 HHH FFF 10

 Sample Output 2:
 0
 */

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define Atoi(ch) (((ch[0]-'A')*26+(ch[1]-'A'))*26+ch[2]-'A')

void Itoa(int a, char* head);

class Node {
public:
	int root;
	int maxweight;
	int headid;
	int gangsize;
	int totalweight;
	int weight;
	bool isgang;

	bool operator<(const Node &node) const {
		return headid < node.headid;
	}
};

int findroot(int, Node*, int);

int main() {
	int ncall, threhold;

	Node nodes[26 * 26 * 26];

	scanf("%d %d", &ncall, &threhold);

	for (int i = 0; i < 26 * 26 * 26; i++) {
		nodes[i].root = i;
		nodes[i].gangsize = 1;
		nodes[i].headid = i;
		nodes[i].weight = 0;
		nodes[i].maxweight = 0;
		nodes[i].totalweight = 0;
		nodes[i].isgang = false;
	}

	for (int i = 0; i < ncall; i++) {
		char A[4], B[4];
		int time;

		scanf("%s %s %d", A, B, &time);

		if (time > 1000) {
			continue;
		}

		int root1 = findroot(Atoi(A), nodes, time);
		int root2 = findroot(Atoi(B), nodes, time);

		if (root1 != root2) {
			if (nodes[root1].maxweight > nodes[root2].maxweight) {
				nodes[root2].root = root1;
				nodes[root1].gangsize += nodes[root2].gangsize;
				nodes[root1].totalweight += nodes[root2].totalweight;
				nodes[root1].totalweight += time;
				if (nodes[root1].gangsize > 2
						&& nodes[root1].totalweight > threhold) {
					nodes[root1].isgang = true;
				}
				nodes[root2].isgang = false;
			} else {
				nodes[root1].root = root2;
				nodes[root2].gangsize += nodes[root1].gangsize;
				nodes[root2].totalweight += nodes[root1].totalweight;
				nodes[root2].totalweight += time;
				if (nodes[root2].gangsize > 2
						&& nodes[root2].totalweight > threhold) {
					nodes[root2].isgang = true;
				}
				nodes[root1].isgang = false;
			}
		} else {
			nodes[root1].totalweight += time;
			if (nodes[root1].gangsize > 2
					&& nodes[root1].totalweight > threhold) {
				nodes[root1].isgang = true;
			}
		}
	}

	vector<Node> head;

	for (int i = 0; i < 26 * 26 * 26 - 1; i++) {
		if (nodes[i].isgang) {
			head.push_back(nodes[i]);
		}
	}

	printf("%d\n", head.size());

	sort(head.begin(), head.end());

	for (int i = 0; i < head.size(); i++) {
		char h[4];
		Itoa(head[i].headid, h);
		printf("%s %d\n", h, head[i].gangsize);
	}

//  system("pause");
	return 0;
}

int findroot(int id, Node* nodes, int time) {
	int root;
	int weight = nodes[id].weight += time;
	int newid = id;
	while ((root = nodes[id].root) != id) {
		nodes[id].root = nodes[root].root;
		id = root;
	}

	if (nodes[root].maxweight < weight) {
		nodes[root].maxweight = weight;
		nodes[root].headid = newid;
	}

	return root;
}

void Itoa(int a, char* head) {

	head[3] = '\0';
	for (int i = 0; i < 3; i++) {
		head[2 - i] = (char) ('A' + a % 26);
		a = a / 26;
	}

}

