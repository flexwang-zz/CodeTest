/*
 ﻿This time, you are supposed to find A*B where A and B are two polynomials.
 Input Specification:
 Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
 Output Specification:
 For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
 Sample Input
 2 1 2.4 0 3.2
 2 2 1.5 1 0.5

 Sample Output
 3 3 3.6 2 6.0 1 1.6
 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

void read_poly(unordered_map<int,float> &um) {
	int k;
	cin >> k;
	while (k--) {
		int a;
		float b;
		cin >> a >> b;
		um[a] += b;
	}
}


int main()
{
	unordered_map<int, float> ua, ub;
	map<int, float> uc;
	read_poly(ua);
	read_poly(ub);
	for (auto &x : ua)
		for (auto &y : ub)
			uc[x.first+y.first] += x.second*y.second;
	vector<pair<int, float>> res;
	for (auto &x : uc)
		if (x.second != 0.f)
			res.push_back(x);
	if (res.size() == 0) printf("0");
	else {
		printf("%d ", res.size());
		for (int i=res.size()-1; i>=0; --i)
			printf("%d %.1f%c", res[i].first, res[i].second, i?' ':'\n');
	}
	return 0;
}