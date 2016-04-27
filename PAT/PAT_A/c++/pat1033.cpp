/*
 ﻿With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
 Sample Input 1:
 50 1300 12 8
 6.00 1250
 7.00 600
 7.00 150
 7.10 0
 7.20 200
 7.50 400
 7.30 1000
 6.85 300

 Sample Output 1:
 749.17

 Sample Input 2:
 50 1300 12 2
 7.10 0
 7.00 600

 Sample Output 2:
 The maximum travel distance = 1200.00
 */

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Node {
public:
	float dist;
	float price;

	bool operator<(const Node&node) const {
		return dist < node.dist;
	}
};

int main() {
	float capacity, dist, d;
	int nstation;

	scanf("%f %f %f %d", &capacity, &dist, &d, &nstation);

	vector<Node> stations;

	for (int i = 0; i < nstation; i++) {
		Node node;

		scanf("%f %f", &node.price, &node.dist);

		stations.push_back(node);
	}

	sort(stations.begin(), stations.end());

	if (stations[0].dist > 0.f) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}

	vector<float> gas;
	vector<float> price;
	float money;
	float curdist;

//  gas.push_back(capacity);
//  price.push_back(stations[0].price);
	money = 0.f;
	curdist = 0.f;

	int curstation = -1;

	while (true) {
		curstation++;

		if (curstation == nstation
				|| (curdist + capacity * d) < stations[curstation].dist) {
			if (curdist + capacity * d >= dist) {
				float newdist = dist - curdist;

				vector<float>::iterator itergas = gas.begin();
				vector<float>::iterator iterprice = price.begin();

				while (newdist > 0.f) {
					if (*itergas * d > newdist) {
						*itergas -= newdist / d;
						money += newdist / d * *iterprice;
						newdist = 0.f;
					} else if (*itergas * d == newdist) {
						money += newdist / d * *iterprice;
						*itergas = 0.f;
						newdist = 0.f;
						gas.erase(itergas);
						price.erase(iterprice);
					} else {
						money += *itergas * *iterprice;
						newdist -= *itergas * d;
						gas.erase(itergas);
						price.erase(iterprice);
					}
				}
				printf("%.2f", money);
				break;
			}
			printf("The maximum travel distance = %.2f",
					curdist + capacity * d);
			break;
		}

		float newdist = stations[curstation].dist - curdist;

		curdist = stations[curstation].dist;

		vector<float>::iterator itergas = gas.begin();
		vector<float>::iterator iterprice = price.begin();
		while (newdist > 0.f) {
			if (*itergas * d > newdist) {
				*itergas -= newdist / d;
				money += newdist / d * *iterprice;
				newdist = 0.f;
			} else if (*itergas * d == newdist) {
				money += newdist / d * *iterprice;
				*itergas = 0.f;
				newdist = 0.f;
				gas.erase(itergas);
				price.erase(iterprice);
			} else {
				money += *itergas * *iterprice;
				newdist -= *itergas * d;
				gas.erase(itergas);
				price.erase(iterprice);
			}
		}

		//after get to the new station fill the tank
		float curprice = stations[curstation].price;

		float curgas = 0.f;
		while (true) {
			if (iterprice == price.end()) {
				price.push_back(curprice);
				gas.push_back(capacity - curgas);
				break;
			}
			if (*iterprice < curprice) {
				curgas += *itergas;
				iterprice++;
				itergas++;
			} else if (*iterprice >= curprice) {
				*itergas = capacity - curgas;
				*iterprice = curprice;
				iterprice++;
				itergas++;

				gas.erase(itergas, gas.end());
				price.erase(iterprice, price.end());

				break;
			}
		}
	}

	return 0;
}

