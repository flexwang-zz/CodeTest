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

#include<stdio.h>
#include<string.h>

int maxsym(char*, int, int);
int maxsym2(char*, int, int);

int main() {
	char ch[1001];
	int len;

	gets(ch);

	len = strlen(ch);

	int maxs = 0;

	for (int pivot = 0; pivot < len; pivot++) {
		int cur = maxsym(ch, pivot, len);
		int cur2 = maxsym2(ch, pivot, len);
		if (cur > maxs) {
			maxs = cur;
		}
		if (cur2 > maxs) {
			maxs = cur2;
		}
	}
	printf("%d", maxs);

//  while(1);
	return 0;
}

int maxsym(char* ch, int pivot, int size) {
	int len = 1;
	int shift = 1;

	while (true) {
		if ((pivot - shift) < 0 || (pivot + shift) > (size - 1)) {
			return len;
		}

		if (ch[pivot - shift] == ch[pivot + shift]) {
			len += 2;
		} else {
			return len;
		}
		shift++;
	}
}

int maxsym2(char* ch, int pivot, int size) {
	int len = 0;
	int shift = 0;

	while (true) {
		if ((pivot - shift) < 0 || (pivot + 1 + shift) > (size - 1)) {
			return len;
		}

		if (ch[pivot - shift] == ch[pivot + 1 + shift]) {
			len += 2;
		} else {
			return len;
		}
		shift++;
	}
}

