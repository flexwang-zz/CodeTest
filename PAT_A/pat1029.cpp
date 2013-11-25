/*
 ﻿Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
 Given two increasing sequences of integers, you are asked to find their median.
 Input
 Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
 Output
 For each test case you should output the median of the two given sequences in a line.
 Sample Input
 4 11 12 13 14
 5 9 10 15 16 17

 Sample Output
 13
 */

#include<vector>
#include<stdio.h>

using namespace std;

int main() {
	vector<long int> v1, v2;

	long int n1, n2;

	scanf("%ld", &n1);

	for (long int i = 0; i < n1; i++) {
		long int a;
		scanf("%ld", &a);
		v1.push_back(a);
	}

	scanf("%ld", &n2);
	vector<long int>::iterator iter1 = v1.begin();

	for (long int i = 0; i < n2; i++) {
		long int a;
		scanf("%ld", &a);

		while (iter1 != v1.end() && *iter1 <= a) {
			if (*iter1 != a) {
				v2.push_back(*iter1);
			}
			iter1++;
		}

		v2.push_back(a);
	}

	while (iter1 != v1.end()) {
		v2.push_back(*iter1);
		iter1++;
	}

	for (int i = 0; i < v2.size(); i++) {
//    printf("%ld ", v2[i]);
	}

	printf("%ld", v2[(v2.size() - 1) / 2]);

//  while(1);
	return 0;
}

