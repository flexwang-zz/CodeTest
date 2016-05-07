/*
 ﻿A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
 Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
 Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
 Input Specification:
 Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.
 Output Specification:
 For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
 Sample Input 1:
 67 3

 Sample Output 1:
 484
 2

 Sample Input 2:
 69 3

 Sample Output 2:
 1353
 3

 */
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string add(const string &s, const string &t)
{
	string r;
	int c = 0;
	for (int i=0; i<s.length(); ++i) {
		int v = s[i]-'0'+t[i]-'0'+c;
		c = v/10;
		r += '0' + v%10;
	}
	if (c) r += '0'+c;
	reverse(r.begin(), r.end());
	return r;
}

bool is_pal(const string &s)
{
	for (int i=0, j=s.length()-1; i<j; ++i,--j)
		if (s[i] != s[j]) return false;
	return true;
}

int main()
{
	string str;
	int k, i;
	cin >> str >> k;
	i = 0;
	while (!is_pal(str) && i < k) {
		string r = str;
		reverse(r.begin(), r.end());
		str = add(str, r);
		++i;
	}
	cout << str << endl << i << endl;
	return 0;
}