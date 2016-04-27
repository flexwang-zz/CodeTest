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

#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

ll findK(vector<ll>& nums1, int s1, int t1, vector<ll>& nums2, int s2, int t2, int k){
    if (s1 == t1) return nums2[s2+k];
    if (s2 == t2) return nums1[s1+k];
    ll m1 = s1 + (t1-s1)/2, m2 = s2 + (t2-s2)/2;
    ll m = m1-s1+m2-s2+1;
    if (k < m) {
        if (nums1[m1] < nums2[m2])
            return findK(nums1, s1, t1, nums2, s2, m2, k);
        else 
            return findK(nums1, s1, m1, nums2, s2, t2, k);
    }
    else {
        if (nums1[m1] > nums2[m2])
            return findK(nums1, s1, t1, nums2, m2+1, t2, k-(m2-s2+1));
        else
            return findK(nums1, m1+1, t1, nums2, s2, t2, k-(m1-s1+1));     
    }
}

int main() {
	int n1, n2;
	cin >> n1;
	vector<ll> v1(n1);
	for (auto &x : v1)
		scanf("%lld", &x);
	cin >> n2;
	vector<ll> v2(n2);
	for (auto &x: v2)
		scanf("%lld", &x);
	cout << findK(v1, 0, v1.size(), v2, 0, v2.size(), (n1+n2-1)/2) << endl;
	return 0;
}

