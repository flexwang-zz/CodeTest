/*
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost". Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.

Output Specification:

For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommended. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route. Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM".

Sample Input:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:
3 3 195 97
HZH->PRS->ROM
*/

#include <stdio.h>
#include <vector>
using namespace std;


int name2i(char ch[4]) {
	return ch[2] - 'A' + (ch[1] - 'A') * 26 + (ch[0] - 'A') * 26 * 26;
}

void i2name(char ch[4], int id) {
	ch[3] = '\0';
	ch[2] = id % 26 + 'A';
	ch[1] = id / 26 % 26 + 'A';
	ch[0] = id / 26 / 26 % 26 + 'A';
}

struct Node
{
	Node() : isnode(false), known(false), happness(0), dist(-1), npath(0), nnode(0), nhappness(0){}
	bool isnode;
	bool known;
	int dist;
	int happness;

	vector<int> path;
	vector<int>	adjacent;
	vector<int> adjacent_dist;

	int npath;
	int nnode;
	int nhappness;
};

#define SIZE 26*26*26

Node nodes[SIZE];

int main()
{
	int ncity, npath;
	char start[4];

	scanf("%d %d %s", &ncity, &npath, start);

	int s = name2i(start);

	for (int i = 0; i < ncity-1; i++) {
		char name[4];
		int happness;
		scanf("%s %d", name, &happness);
		
		int id = name2i(name);
		nodes[id].happness = happness;
		nodes[id].isnode = true;
	}

	for (int i = 0; i < npath; i++) {
		char name1[4], name2[4];
		int dist;

		scanf("%s %s %d", name1, name2, &dist);

		int id1 = name2i(name1);
		int id2 = name2i(name2);

		nodes[id1].adjacent.push_back(id2);
		nodes[id1].adjacent_dist.push_back(dist);

		nodes[id2].adjacent.push_back(id1);
		nodes[id2].adjacent_dist.push_back(dist);
	}

	int rom = name2i("ROM");

	nodes[s].dist = 0;
	nodes[s].npath = 1;
	nodes[s].isnode = true;
	nodes[s].path.push_back(s);

	while (!nodes[rom].known) {

		int min_index = -1;

		for (int i = 0; i < SIZE; i++) {
			if (!nodes[i].isnode || nodes[i].known || nodes[i].dist == -1)
				continue;

			if (min_index == -1 || nodes[min_index].dist > nodes[i].dist)
				min_index = i;
		}

		if (min_index == -1)
			break;

		nodes[min_index].known = true;

		Node &target = nodes[min_index];

		for (int i = 0; i < target.adjacent.size(); i++) {
			Node &adj = nodes[target.adjacent[i]];

			if (adj.dist == -1 || adj.dist > target.dist + target.adjacent_dist[i]) {
				adj.dist = target.dist + target.adjacent_dist[i];
				adj.path = target.path;
				adj.path.push_back(target.adjacent[i]);
				adj.nhappness = adj.happness + target.nhappness;
				adj.nnode = target.nnode + 1;
				adj.npath = target.npath;
			}
			else if (adj.dist == target.dist + target.adjacent_dist[i]) {
				adj.npath += target.npath;
				if (adj.nhappness < adj.happness + target.nhappness ||
					adj.nhappness == adj.happness + target.nhappness && adj.nnode > target.nnode + 1) {
					adj.path = target.path;
					adj.path.push_back(target.adjacent[i]);
					adj.nhappness = adj.happness + target.nhappness;
					adj.nnode = target.nnode + 1;
				}
			}
		}
	}

	printf("%d %d %d %d\n", nodes[rom].npath, nodes[rom].dist, nodes[rom].nhappness, nodes[rom].nhappness / nodes[rom].nnode);

	for (int i = 0; i < nodes[rom].path.size(); i++) {
		if (i)	printf("->");
		char name[4];
		i2name(name, nodes[rom].path[i]);
		printf("%s", name);
	}

	printf("\n");

	return 0;
}