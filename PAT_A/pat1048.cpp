/*
 ﻿Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 105 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=105, the total number of coins) and M(<=103, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output "No Solution" instead.
 Sample Input 1:
 8 15
 1 2 8 7 2 4 11 15

 Sample Output 1:
 4 11

 Sample Input 2:
 7 14
 1 8 7 2 4 11 15

 Sample Output 2:
 No Solution
 */

#include<stdio.h>
#include<vector>

#define min(a,b) (a<b)?a:b

using namespace std;

int main() {
	int bucket[501];

	int ncoin, money;

	for (int i = 0; i <= 500; i++) {
		bucket[i] = 0;
	}

	scanf("%d %d", &ncoin, &money);

	int v1 = money + 1;
	for (int i = 0; i < ncoin; i++) {
		int value;

		scanf("%d", &value);

		if (value <= 0 || value > 500) {
			continue;
		}

		if (bucket[value] < 2) {

			int v2 = money - value;

			if (v2 > 0 && v2 <= 500) {
				if (bucket[v2] > 0) {
					if ((min(value, v2)) < v1) {
						v1 = min(value, v2);
					}
				}
			}
			bucket[value]++;
		}
	}

	if (v1 <= money) {
		printf("%d %d", v1, money - v1);
	} else {
		printf("No Solution");
	}

	return 0;
}

