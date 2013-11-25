/*
 ﻿A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.
 Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.
 Then K lines follow, each describes a road in the format
 P1 P2 Dist
 where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.
 Output Specification:
 For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.
 Sample Input 1:
 4 3 11 5
 1 2 2
 1 4 2
 1 G1 4
 1 G2 3
 2 3 2
 2 G2 1
 3 4 2
 3 G3 2
 4 G1 3
 G2 G1 1
 G3 G2 2

 Sample Output 1:
 G1
 2.0 3.3

 Sample Input 2:
 2 1 2 10
 1 G1 9
 2 G1 20

 Sample Output 2:
 No Solution




 */
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

#define max (-1)

class Node {
public:
	vector<int> adjacent;
	vector<int> adjacentdist;
	int dist;
	bool known;
};

class Candidate {
public:
	int id;
	float avaragedist;
	float mindist;

	bool operator<(const Candidate can) const {
		if (mindist == can.mindist) {
			if (avaragedist == can.avaragedist) {
				return id < can.id;
			}

			return avaragedist < can.avaragedist;
		}
		return mindist > can.mindist;
	}
};

int Atoi(char *);

int main() {
	int nhouse, ncandidate, nroad, maxrange;

	Node houses[1011];

	vector<Candidate> validcandidates;

	scanf("%d %d %d %d", &nhouse, &ncandidate, &nroad, &maxrange);

	for (int i = 0; i < nroad; i++) {
		char A[5], B[5];
		int len;

		scanf("%s %s %d", A, B, &len);

		int a = Atoi(A);
		int b = Atoi(B);

		houses[a].adjacent.push_back(b);
		houses[a].adjacentdist.push_back(len);

		houses[b].adjacent.push_back(a);
		houses[b].adjacentdist.push_back(len);

	}

	for (int k = 1; k <= ncandidate; k++) {
		//initialize
		for (int j = 1; j <= nhouse; j++) {
			houses[j].dist = max;
			houses[j].known = false;
		}

		for (int j = 1001; j <= 1000 + ncandidate; j++) {
			houses[j].dist = max;
			houses[j].known = false;
		}

		houses[k + 1000].dist = 0;

		int nknown = 0;
		int totaldist = 0;
		int globalmindist = max;

		while (true) {
			int mindist = max;
			int minindex = -1;
			for (int i = 1; i <= nhouse; i++) {
				if (houses[i].dist == max || houses[i].known) {
					continue;
				}

				if (mindist == max || mindist > houses[i].dist) {
					mindist = houses[i].dist;
					minindex = i;
				}
			}

			for (int i = 1001; i <= 1000 + ncandidate; i++) {
				if (houses[i].dist == max || houses[i].known) {
					continue;
				}

				if (mindist == max || mindist > houses[i].dist) {
					mindist = houses[i].dist;
					minindex = i;
				}
			}

			if (minindex < 0 || (mindist > maxrange && (minindex <= 1000))) {
				break;
			}

			if ((minindex <= 1000)
					&& (globalmindist == max && mindist > 0
							|| globalmindist > mindist && mindist > 0)) {
				globalmindist = mindist;
			}

			houses[minindex].known = true;

			if (minindex <= 1000) {
				totaldist += houses[minindex].dist;
				nknown++;
			}

			if (nknown > nhouse) {
				break;
			}

			Node house = houses[minindex];
			for (int i = 0; i < house.adjacent.size(); i++) {
				Node* adjacent = &houses[house.adjacent[i]];

				if (adjacent->known) {
					continue;
				}

				if (adjacent->dist == max
						|| adjacent->dist
								> (house.dist + house.adjacentdist[i])) {
					adjacent->dist = house.dist + house.adjacentdist[i];
				}
			}
		}

		if (nknown >= nhouse) {
			Candidate can;
			can.id = k;
			can.avaragedist = (float) totaldist / (float) nhouse;
			can.mindist = globalmindist;

			validcandidates.push_back(can);
		}
	}

	if (validcandidates.size() <= 0) {
		printf("No Solution");
	} else {
		sort(validcandidates.begin(), validcandidates.end());
		printf("G%d\n%.1f %.1f", validcandidates[0].id,
				validcandidates[0].mindist, validcandidates[0].avaragedist);
	}

	return 0;
}

int Atoi(char *a) {
	if (a[0] == 'G') {
		return atoi(a + 1) + 1000;
	}

	return atoi(a);
}

