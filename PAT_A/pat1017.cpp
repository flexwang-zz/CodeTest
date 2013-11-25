/*
 ﻿Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.
 Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
 Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.
 Output Specification:
 For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.
 Sample Input:
 7 3
 07:55:00 16
 17:00:01 2
 07:59:59 15
 08:01:00 60
 08:00:00 30
 08:00:02 2
 08:03:00 10

 Sample Output:
 8.2
 */
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>

#define max(a,b) ((a>b)?a:b)

using namespace std;

class customer {
public:
	static const int eight = 8 * 60 * 60;
	int arrivingtime;
	int lasttime;
	int waittime;
	int servetime;

	customer(char* arrivetime, int ltime) {
		char tmp[3];
		arrivingtime = -eight;
		waittime = 0;
		//hour
		tmp[0] = arrivetime[0];
		tmp[1] = arrivetime[1];

		arrivingtime += atoi(tmp) * 60 * 60;

		//minute
		tmp[0] = arrivetime[3];
		tmp[1] = arrivetime[4];

		arrivingtime += atoi(tmp) * 60;

		//second
		tmp[0] = arrivetime[6];
		tmp[1] = arrivetime[7];

		arrivingtime += atoi(tmp);

		lasttime = ltime * 60;

	}

	bool operator <(const customer &another) const {
		return arrivingtime < another.arrivingtime;
	}
};

int main() {
	int ncustomer, nwindow;
	vector<customer> customers;
	scanf("%d %d", &ncustomer, &nwindow);

	for (int i = 0; i < ncustomer; i++) {
		char time[30];
		int lasttime;

		scanf("%s %d", time, &lasttime);

		if (lasttime > 60) {
			lasttime = 60;
		}
		customer c = customer(time, lasttime);
		if (c.arrivingtime > 32400) {
			continue;
		}
		customers.push_back(c);
	}
	ncustomer = customers.size();

//  printf("%d\n", ncustomer);
	sort(customers.begin(), customers.end());

	int windows[110];
	int i;
	int ntime = 0;
	int totalwaittime = 0;
	for (i = 0; i < ncustomer; i++) {
		if (i < nwindow) {
			windows[i] = i;
			totalwaittime += max(0, ntime - customers[i].arrivingtime);
			customers[i].waittime = max(0, ntime - customers[i].arrivingtime);
//      printf("wait:%d\n", customers[i].waittime);
		} else {
			//find the earliest
			vector<int> earliestwindow;
			int earliesttime = 5000001;
			for (int j = 0; j < nwindow; j++) {
				int totaltime = max(customers[windows[j]].arrivingtime, 0)
						+ customers[windows[j]].lasttime - ntime;
//        printf("totaltime:%d\n", totaltime);
				if (totaltime < 0) {
//          printf("%d %d\n", customers[windows[j]].arrivingtime, customers[windows[j]].lasttime);
				}
				if (totaltime < earliesttime) {
					earliesttime = totaltime;
					earliestwindow = vector<int>();
					earliestwindow.push_back(j);
				} else if (totaltime == earliesttime) {
					earliestwindow.push_back(j);
				}
			}

//      printf("here:%d\n", earliestwindow.size());

//      printf("earliesttiem: %d\n", earliesttime);
			ntime += earliesttime;
//      printf("ntime: %d\n", ntime);
			windows[earliestwindow[0]] = i;
			customers[i].waittime = max(0, ntime - customers[i].arrivingtime);
			totalwaittime += max(0, ntime - customers[i].arrivingtime);
			customers[i].arrivingtime = max(ntime, customers[i].arrivingtime);
//      printf("wait:%d\n", customers[i].waittime);
		}
	}

	printf("%.1f", totalwaittime / (float) ncustomer / 60.f);

//  while(1);
	return 0;
}

