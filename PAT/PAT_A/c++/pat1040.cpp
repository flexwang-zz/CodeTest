/*
 ﻿Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.
 Input Specification:
 Each input file contains one test case which gives a non-empty string of length no more than 1000.
 Output Specification:
 For each test case, simply print the maximum length in a line.
 Sample Input:
 Is PAT&TAP symmetric?

 Sample Output:
 11
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>

using std::max;

const int max_n = 1001;
char s[max_n];

int main()
{
	gets(s);
	int len = strlen(s);
	int res = 0;
	for (int i=0; i<len; ++i) {
		for (int j=0; i-j>=0 && i+j<len; ++j) 
			if (s[i+j] != s[i-j]) break;
			else res = max(res, 1+2*j);
		for (int j=0; i-j>=0 && i+j+1<len; ++j)
			if (s[i+j+1] != s[i-j]) break;
			else res = max(res, 2+2*j);
	}
	printf("%d\n", res);
	return 0;
}
