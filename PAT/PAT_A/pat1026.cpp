/*
 ﻿A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.
 Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.
 One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.
 Output Specification:
 For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.
 Sample Input:
 9
 20:52:00 10 0
 08:00:00 20 0
 08:02:00 30 0
 20:51:00 10 0
 08:10:00 5 0
 08:12:00 10 1
 20:50:00 10 0
 08:01:30 15 1
 20:53:00 10 1
 3 1
 2

 Sample Output:
 08:00:00 08:00:00 0
 08:01:30 08:01:30 0
 08:02:00 08:02:00 0
 08:12:00 08:16:30 5
 08:10:00 08:20:00 10
 20:50:00 20:50:00 0
 20:51:00 20:51:00 0
 20:52:00 20:52:00 0
 3 3 2


 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>

#define min(a,b) ((a>b)?b:a)
#define max(a,b) ((a>b)?a:b)

using namespace std;

struct Table {
	bool isVip;
	int customer;
	int nserved;
	Table() :
			isVip(false), customer(-1), nserved(0) {
	}
};

class Customer {
public:
	int arrivetime;
	int servetime;
	char arrive[10];
	int lasttime;
	bool isVip;
	bool served;

	Customer() {
		served = false;
	}

	Customer(char* a, int l, int isvip) {
		char tmp[3];

		arrivetime = 0;
		//hour
		tmp[0] = a[0];
		tmp[1] = a[1];

		arrivetime += atoi(tmp) * 3600;

		//minute
		tmp[0] = a[3];
		tmp[1] = a[4];

		arrivetime += atoi(tmp) * 60;
		//second
		tmp[0] = a[6];
		tmp[1] = a[7];

		arrivetime += atoi(tmp);

		lasttime = min(l * 60, 7200);

		isVip = (isvip == 1);

		served = false;

	}

	bool operator<(const Customer& another) const {
		return arrivetime < another.arrivetime;
	}

	void print(int ntime) {
		if (ntime >= 21 * 3600) {
			return;
		}
		subprint(arrivetime);
		printf(" ");
		subprint(ntime);
		printf(" ");
		int duration = ntime - arrivetime;
		if (duration % 60 >= 30) {
			duration = duration + (60 - duration % 60);
		}
		printf("%d\n", duration / 60);
	}

	static void subprint(int ntime) {
		int seconds = ntime % 60;
		ntime = (ntime - seconds) / 60;
		int min = ntime % 60;
		ntime = (ntime - min) / 60;
		printf("%02d:%02d:%02d%", ntime, min, seconds);
	}
};

int main() {
	int ncustomer, ntable, nvip;
	int eight = 8 * 3600;
	vector<Customer> customers;
	vector<int> viptables;
	vector<int> vipcustomers;
	Table tables[102];
	scanf("%d", &ncustomer);

	for (int i = 0; i < ncustomer; i++) {
		char a[15];
		int last, vip;

		scanf("%s %d %d", a, &last, &vip);
		Customer c(a, last, vip);

		if (c.arrivetime >= 8 * 3600 && c.arrivetime < 21 * 3600) {
			customers.push_back(c);
		}
	}

	sort(customers.begin(), customers.end());

	ncustomer = customers.size();

	for (int i = 0; i < customers.size(); i++) {
		//  customers[i].subprint(customers[i].arrivetime);
		//  printf(" %d ", customers[i].lasttime/60);
		//  printf("%d", customers[i].isVip);
		//printf("\n");
	}

	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].isVip) {
			vipcustomers.push_back(i);
		}
	}

	scanf("%d %d", &ntable, &nvip);

	for (int i = 0; i < nvip; i++) {
		int vipid;
		scanf("%d", &vipid);
		tables[vipid].isVip = true;
		viptables.push_back(vipid);
	}

	sort(viptables.begin(), viptables.end());

	int ntime = 8 * 3600;

	int noccupied = 0;
	int i;
	for (i = 0; i < customers.size(); i++) {
		//printf("%d %d ", noccupied, ntable);
		if (ntime >= 21 * 3600) {
			continue;
		}
#ifdef debug
		Customer::subprint(ntime);
		printf("->");
		for( int j=1; j<=ntable; j++)
		{
			printf("%d ", tables[j].customer);
		}
		printf("\n");
#endif
		if (customers[i].served) {
			continue;
		}
		//find the earliest
		int minindex = -1;
		vector<int> minindexes;
		int mintime = 99999999;
		for (int itable = 1; itable <= ntable; itable++) {
			int customerid = tables[itable].customer;

			if (customerid >= 0) {
				int finishtime = customers[customerid].servetime
						+ customers[customerid].lasttime;
				if (finishtime < mintime) {
					minindexes.clear();
					minindexes.push_back(itable);
					mintime = finishtime;
					minindex = itable;
				} else if (finishtime == mintime) {
					minindexes.push_back(itable);
					mintime = finishtime;
					minindex = itable;
				}
			}
		}

		if (minindexes.size() > 0) {
			if (mintime <= customers[i].arrivetime) {
				ntime = mintime;
				for (int iindex = 0; iindex < minindexes.size(); iindex++) {
					customers[tables[minindexes[iindex]].customer].served =
							true;
					tables[minindexes[iindex]].customer = -1;
					noccupied--;
				}
				i--;
				//  printf("no one in\n");
				continue;
			} else if (noccupied >= ntable) {
//        Customer::subprint(mintime);
//        printf("\n");
				ntime = mintime;
				if (mintime >= 21 * 3600) {
					break;
				}

				//vector<int> waitingqueue;
				for (int iindex = 0; iindex < minindexes.size(); iindex++) {
					tables[minindexes[iindex]].customer = -1;
					noccupied--;
				}

				int tmpi = i;
				for (int iindex = 0; iindex < minindexes.size(); iindex++) {
					if (!tables[minindexes[iindex]].isVip) {
						continue;
					}
					bool foundvip = false;

					int j;
					for (j = i;
							j < customers.size()
									&& customers[j].arrivetime <= ntime; j++) {
						if (customers[j].served) {
							continue;
						}
						if (customers[j].isVip) {
							foundvip = true;
							break;
						}
					}
					if (foundvip) {
						tables[minindexes[iindex]].customer = j;
						tables[minindexes[iindex]].nserved++;
						customers[j].served = true;
						customers[j].servetime = ntime;
						noccupied++;
						if (i == j) {
							tmpi++;
						}
						customers[j].print(ntime);
					} else {
						break;
					}
				}
				for (int iindex = 0; iindex < minindexes.size(); iindex++) {
					if (tables[minindexes[iindex]].customer >= 0) {
						continue;
					}
					for (int j = i;
							j < customers.size()
									&& customers[j].arrivetime <= ntime; j++) {
						if (!customers[j].served) {
							tables[minindexes[iindex]].customer = j;
							tables[minindexes[iindex]].nserved++;
							customers[j].served = true;
							;
							customers[j].servetime = ntime;
							customers[i].print(ntime);
							if (j == i) {
								tmpi++;
							}
							noccupied++;
							break;
						}
					}
				}
				i = tmpi - 1;
			} else {
				int tableid;
				if (customers[i].isVip) {
					if (viptables.size() > 0) {
						bool findavailableviptable = false;
						for (int j = 0; j < viptables.size(); j++) {
							if (tables[viptables[j]].customer < 0) {
								findavailableviptable = true;
								tableid = viptables[j];
								break;
							}
						}
						if (!findavailableviptable) {
							for (int j = 1; j <= ntable; j++) {
								if (tables[j].customer < 0) {
									tableid = j;
									break;
								}
							}
						}

						//tableid = viptables[0];
					} else {
						for (int j = 1; j <= ntable; j++) {
							if (tables[j].customer < 0) {
								tableid = j;
								break;
							}
						}
					}
				} else {
					for (int j = 1; j <= ntable; j++) {
						if (tables[j].customer < 0) {
							tableid = j;
							break;
						}
					}
				}
				tables[tableid].customer = i;
				tables[tableid].nserved++;
				noccupied++;
				ntime = customers[i].arrivetime;
				customers[i].print(ntime);
				customers[i].served = true;
				customers[i].servetime = ntime;
			}
		} else {
			int tableid;
			if (customers[i].isVip) {
				if (viptables.size() > 0) {
					tableid = viptables[0];
				} else {
					tableid = 1;
				}
			} else {
				tableid = 1;
			}
			tables[tableid].customer = i;
			tables[tableid].nserved++;

			noccupied++;
			ntime = customers[i].arrivetime;
			customers[i].served = true;
			customers[i].print(ntime);
			customers[i].servetime = ntime;

		}

	}

	bool firstprint = true;
	for (int i = 1; i <= ntable; i++) {
		if (firstprint) {
			firstprint = false;
		} else {
			printf(" ");
		}
		printf("%d", tables[i].nserved);
	}
	return 0;
}

