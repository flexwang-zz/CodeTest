/*
 ﻿Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.
 Input Specification:
 Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 10^4. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
 Output Specification:
 For each test case, print S1 - S2 in one line.
 Sample Input:
 They are students.
 aeiou

 Sample Output:
 Thy r stdnts.

 */

#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int ctoi(char c) {
	if (c == ' ') {
		return 0;
	}
	if (c <= 'Z' && c >= 'A') {
		return 1 + c - 'A';
	}
	if (c <= 'z' && c >= 'a') {
		return 50 + c - 'a';
	}
}

int main() {
	bool bucket[256];

	for (int i = 0; i < 256; i++) {
		bucket[i] = true;
	}

	char s1[10002], s2[100002];

	int ndelete = 0;
	char ch;
	int len = 0;

	while ((s1[len++] = getchar()) != '\n')
		;

	while ((ch = getchar()) != '\n') {
		if (bucket[ch]) {
			ndelete++;
			bucket[ch] = false;

			if (ndelete > 256) {
				break;
			}
		}

	}

	for (int i = 0; i < len; i++) {
		if (bucket[s1[i]]) {
			printf("%c", s1[i]);
		}
	}

	return 0;
}

