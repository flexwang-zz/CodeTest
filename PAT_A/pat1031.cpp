/*
 ﻿Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:
 h  d
 e  l
 l  r
 lowo

 That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
 Input Specification:
 Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.
 Output Specification:
 For each test case, print the input string in the shape of U as specified in the description.
 Sample Input:
 helloworld!

 Sample Output:
 h   !
 e   d
 l   l
 lowor
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str[82];

	scanf("%s", str);

	int N = strlen(str);

	int n2, n, N2;

	n = -1;
	for (n2 = 3; n2 <= N; n2++) {
		if ((N + 2 - n2) % 2) {
			continue;
		}

		if ((N + 2 - n2) / 2 <= n2) {
			if ((N + 2 - n2) / 2 > n) {
				n = (N + 2 - n2) / 2;
				N2 = n2;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		printf("%c", str[i]);
		for (int j = 0; j < N2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", str[N - 1 - i]);
	}

	for (int i = (n - 1); i < (n - 1 + N2); i++) {
		printf("%c", str[i]);
	}

	//while(1);
	return 0;
}

