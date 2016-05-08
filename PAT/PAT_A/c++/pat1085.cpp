/*
Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 10^5) is the number of integers in the sequence, and p (<= 1^09) is the parameter. In the second line there are N positive integers, each is no greater than ^109.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
	LL n, p;

	cin >> n >> p;

	vector<LL> v(n);

	for (LL i = 0LL; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	LL result = 0;
	LL end = 0;
	for (LL begin = 0; begin < n; begin++) {
		LL target = v[begin];
		LL e;
		for (e = end; e < n; e++) {
			if (v[e] > target*p) 
				break;
		}

		end = e;

		if (e - begin > result)
			result = e - begin;
	}

	cout << result << endl;

	return 0;

}