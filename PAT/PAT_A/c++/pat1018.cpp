/*
 ﻿There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.
 The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.
 When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

 Figure 1
 Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:
 1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.
 2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.
 Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.
 Sample Input:
 10 3 3 5
 6 7 0
 0 1 1
 0 2 1
 0 3 3
 1 3 1
 2 3 1

 Sample Output:
 3 0->2->3 0
 */

#include<stdio.h>
#include<vector>

using namespace std;

#define max (-1)
#define Max(a,b) ((a>b)?a:b)

int problem;
int abs(int a);

class Path {
public:
	vector<int> p;

	Path() {
		p = vector<int>();
	}

	Path(int ID) {
		p = vector<int>();
		p.push_back(ID);
	}

	void insert(int ID) {
		p.push_back(ID);
	}

	Path& operator+=(int ID) {
		p.push_back(ID);
		return *this;
	}

	Path operator+(int ID) {
		Path newp;
		newp.p.insert(newp.p.begin(), p.begin(), p.end());
		newp.p.push_back(ID);

		return newp;
	}

	void print() {
		for (int i = 1; i < p.size(); i++) {
			printf("%d->", p[i]);
		}
		printf("%d", problem);
	}
};

class Paths {
public:
	vector<Path> p;

	Paths() {
		p = vector<Path>();
	}

	Paths(int ID) {
		p = vector<Path>();
		p.push_back(Path(ID));
	}

	Paths operator+(int ID) {
		Paths newps;
		newps.p.insert(newps.p.end(), p.begin(), p.end());
		for (int i = 0; i < p.size(); i++) {
			newps.p[i] += ID;
		}
		return newps;
	}

	Paths& operator+=(const Paths& another) {
		p.insert(p.end(), another.p.begin(), another.p.end());
		return *this;
	}

	void print() {
		for (int i = 0; i < p.size(); i++) {
			p[i].print();
		}
	}
};

struct Node {
	int nbike;
	vector<int> adjacent;
	vector<float> adjacenttime;
	float time;
	float totaltime;
	bool known;
	Paths ps;

};

int main() {
	int capacity, nstation, nroad;

	scanf("%d %d %d %d", &capacity, &nstation, &problem, &nroad);

	vector<Node> stations;

	Node node;
	node.known = false;
	node.totaltime = 0;
	node.ps = Paths(0);
	stations.push_back(node);
	for (int i = 0; i < nstation; i++) {
		int nbike;
		scanf("%d", &nbike);
		Node node;
		node.known = false;
		node.nbike = nbike;
		node.totaltime = max;
		stations.push_back(node);
	}

	for (int i = 0; i < nroad; i++) {
		int fr, to;
		float time;
		scanf("%d %d %f", &fr, &to, &time);
		stations[fr].adjacent.push_back(to);
		stations[fr].adjacenttime.push_back(time);

		stations[to].adjacent.push_back(fr);
		stations[to].adjacenttime.push_back(time);
	}
	for (int i = 0; i < stations[0].adjacent.size(); i++) {
		//printf("%d ", stations[0].adjacent[i]);
	}
	//printf("\n");
	while (true) {
		//printf("here2");
		//find the min dist unknown vertex
		int minindex = -1;
		float mintotaltime = max;
		for (int i = 0; i < stations.size(); i++) {
			if (stations[i].known || stations[i].totaltime == max) {
				continue;
			}
			if ((mintotaltime == max)
					|| (stations[i].totaltime < mintotaltime)) {
				minindex = i;
				mintotaltime = stations[i].totaltime;
			}
		}

		// if v is not a vertex break
		if (minindex < 0) {
			break;
		}

		//make it known
		stations[minindex].known = true;
		//printf("minindex:%d\n", minindex);
		//adjust the adjacent
		Node minstation = stations[minindex];
		for (int i = 0; i < minstation.adjacent.size(); i++) {
			int adjacentid = minstation.adjacent[i];
			float time = minstation.adjacenttime[i];
			if (stations[adjacentid].known) {
				continue;
			}
			if (((stations[adjacentid].totaltime != max)
					&& stations[adjacentid].totaltime
							> (minstation.totaltime + time))
					|| (stations[adjacentid].totaltime == max)) {

				stations[adjacentid].totaltime = minstation.totaltime + time;
				stations[adjacentid].ps = minstation.ps + minindex;
				//printf("%d\n", adjacentid);
			} else if (stations[adjacentid].totaltime
					== minstation.totaltime + minstation.adjacenttime[i]) {
				stations[adjacentid].ps += (minstation.ps + minindex);
			}
		}
		//printf("here3\n");
	}

	Paths ps = stations[problem].ps;

	int minsend;
	int minrecieve;

	bool firstcompare = true;
	int minindex;

	for (int i = 0; i < ps.p.size(); i++) {
		Path p = ps.p[i];
		p.p.push_back(problem);
		int send = 0;
		int nmore = 0;
		int recieve = 0;
		//forwards
		for (int j = 2; j < p.p.size(); j++) {
			int need = stations[p.p[j]].nbike - capacity / 2;
			//printf("need:%d\n", need);
			if (need > 0) {
				recieve += need;
			} else {
				if (recieve >= -need) {
					recieve -= -need;
				} else {
					send += -need - recieve;
					recieve = 0;
				}
			}
		}

		if (firstcompare) {
			firstcompare = false;
			minindex = i;
			minsend = send;
			minrecieve = recieve;
		} else if (send < minsend) {
			minindex = i;
			minsend = send;
			minrecieve = recieve;
		} else if (send == minsend && recieve < minrecieve) {
			minindex = i;
			minsend = send;
			minrecieve = recieve;
		}
	}

	printf("%d ", minsend);
	ps.p[minindex].print();
	printf(" %d", minrecieve);

//  while(1);
	return 0;
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}

	return a;
}

