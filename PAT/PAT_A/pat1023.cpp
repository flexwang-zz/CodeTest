/*
 ﻿Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
 Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
 Input Specification:
 Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.
 Output Specification:
 For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
 Sample Input:
 1234567899

 Sample Output:
 Yes
 2469135798

 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class BCD {
public:
	int digit[30];
	int permutation[10];
	int len;

	bool operator==(const BCD&another) const {
		for (int i = 0; i < 9; i++) {
			if (permutation[i] != another.permutation[i]) {
				return false;
			}
		}

		return true;
	}

	BCD(char *ch) {
		for (int i = 0; i < 10; i++) {
			permutation[i] = 0;
		}

		len = strlen(ch);

		for (int i = len - 1; i >= 0; i--) {
			digit[len - 1 - i] = ch[i] - '0';
			permutation[digit[len - 1 - i]]++;
		}
	}

	BCD() {
		for (int i = 0; i < 10; i++) {
			permutation[i] = 0;
		}
		len = 0;
	}

	BCD operator*(const int m) const {
		BCD another;

		int carry = 0;
		for (int i = 0; i < len; i++) {
			another.digit[i] = digit[i] * m + carry;
			carry = another.digit[i] / 10;
			another.digit[i] %= 10;
			another.permutation[another.digit[i]]++;
		}

		another.len = len;
		if (carry > 0) {
			another.digit[another.len++] = carry;
			another.permutation[carry]++;
		}

		return another;
	}

	void print(char* tail) {
		for (int i = 0; i < len; i++) {
			printf("%d", digit[len - 1 - i]);
		}
		printf("%s", tail);
	}
};

int main() {
	char str[30];

	scanf("%s", str);

	BCD b(str);

//  b.print("\n");
	if (b == b * 2) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	(b * 2).print("\n");
	//while(1);
	return 0;
}

