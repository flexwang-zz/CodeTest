/*
 ﻿A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
 Input Specification:
 Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
 City1 City2 Distance Cost
 where the numbers are all integers no more than 500, and are separated by a space.
 Output Specification:
 For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.
 Sample Input
 4 5 0 3
 0 1 1 20
 1 3 2 30
 0 3 4 10
 0 2 2 20
 2 3 1 20

 Sample Output
 0 2 3 3 40



 */
#include<stdio.h>
#include<vector>

using namespace std;

#define Max (-1)

class City {
public:
	vector<int> ajacent;
	vector<int> ajacentcost;
	vector<int> ajacentdistance;

	bool known;
	int dist;
	int cost;

	vector<int> path;
};

int main() {
	City cities[500];
	int ncity, nroad, s, d;

	scanf("%d %d %d %d", &ncity, &nroad, &s, &d);

	for (int i = 0; i < nroad; i++) {
		int c1, c2, dist, cost;

		scanf("%d %d %d %d", &c1, &c2, &dist, &cost);

		cities[c1].ajacent.push_back(c2);
		cities[c1].ajacentcost.push_back(cost);
		cities[c1].ajacentdistance.push_back(dist);

		cities[c2].ajacent.push_back(c1);
		cities[c2].ajacentcost.push_back(cost);
		cities[c2].ajacentdistance.push_back(dist);
	}

	for (int i = 0; i < ncity; i++) {
		cities[i].known = false;
		cities[i].cost = Max;
		cities[i].dist = Max;
	}

	cities[s].cost = 0;
	cities[s].dist = 0;

	while (true) {
		int minindex = -1;
		int mindist = Max;
		//find the smallest unkown city
		for (int i = 0; i < ncity; i++) {
			if (cities[i].known || cities[i].dist == Max) {
				continue;
			}

			if (mindist == Max || mindist > cities[i].dist) {
				mindist = cities[i].dist;
				minindex = i;
			}
		}

		if (minindex < 0 || minindex == d) {
			break;
		}

		cities[minindex].known = true;

		City mincity = cities[minindex];
		for (int i = 0; i < mincity.ajacent.size(); i++) {
			//int index = mincity.ajacent[i];
			City *city = &(cities[mincity.ajacent[i]]);
			if (city->known) {
				continue;
			}

			if (city->dist == Max
					|| city->dist > mincity.dist + mincity.ajacentdistance[i]) {
				city->dist = mincity.dist + mincity.ajacentdistance[i];
				city->path = mincity.path;
				city->path.push_back(minindex);
				city->cost = mincity.cost + mincity.ajacentcost[i];
			} else if (city->dist
					== mincity.dist + mincity.ajacentdistance[i]) {
				if (city->cost == Max
						|| city->cost > mincity.cost + mincity.ajacentcost[i]) {
					city->cost = mincity.cost + mincity.ajacentcost[i];
					city->path = mincity.path;
					city->path.push_back(minindex);
				}
			}
		}
	}

	for (int i = 0; i < cities[d].path.size(); i++) {
		printf("%d ", cities[d].path[i]);
	}

	printf("%d %d %d", d, cities[d].dist, cities[d].cost);

	//while(1);
	return 0;
}

