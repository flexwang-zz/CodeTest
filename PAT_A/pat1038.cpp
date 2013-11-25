/*
﻿Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.
Input Specification:
Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the smallest number in one line. Do not output leading zeros.
Sample Input:
5 32 321 3214 0229 87

Sample Output:
22932132143287
*/
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

#define Max(a,b) (a>b)?a:b

using namespace std;

class mystring {
public:
	char str[9];

	bool operator<(const mystring &another) const {
		int len1 = strlen(str);
		int len2 = strlen(another.str);
		int len = Max(len1, len2);

		if (len1 == 0) {
			printf("len1 zero");
		}
		if (len2 == 0) {
			printf("%s\n", another.str);
			printf("len2 zero");
		}
		if (len1 < len) {
			char newstr[9];

			for (int i = 0; i < len; i++) {
				newstr[i] = str[i % len1];
			}

			return strcmp(newstr, another.str) < 0;
		} else if (len2 < len) {
			char newstr[9];

			for (int i = 0; i < len; i++) {
				newstr[i] = another.str[i % len2];
			}

			return strcmp(str, newstr) < 0;
		} else {
			return strcmp(str, another.str) < 0;
		}
	}
};

int main() {
	int nstr;
	vector<mystring> strings;
	scanf("%d", &nstr);

	for (int i = 0; i < nstr; i++) {
		mystring mystr;

		scanf("%s", mystr.str);

//    printf("%d\n", strlen(mystr.str));

		strings.push_back(mystr);
	}

	sort(strings.begin(), strings.end());

//  printf("finish sorting\n");
	bool allzero = true;
	int nzero = 0;

	while (allzero && nzero < nstr) {
		bool prezero = true;
		for (int i = 0; i < strlen(strings[nzero].str); i++) {
			if (prezero && strings[nzero].str[i] == '0') {
				continue;
			} else {
				allzero = false;
				prezero = false;
				printf("%c", strings[nzero].str[i]);
			}
		}
		nzero++;
	}

	for (int i = nzero; i < nstr; i++) {
		printf("%s", strings[i].str);
	}

	if (allzero) {
		printf("0");
	}

//  while(1);
	return 0;
}

