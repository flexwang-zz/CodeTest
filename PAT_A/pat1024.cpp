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

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>

#define max(a,b) ((a>b)?a:b)

using namespace std;

class BCD {
public:
	vector<int> digits;

	BCD() {
	}

	BCD(char *str) {
		int len = strlen(str);
		for (int i = len - 1; i >= 0; i--) {
			digits.push_back(str[i] - '0');
		}
	}

	BCD operator+(const BCD & another) const {
		BCD r;
		int len1 = digits.size();
		int len2 = another.digits.size();
		int len = max(len1, len2);

		int carry = 0;
		for (int i = 0; i < len; i++) {
			int d = carry;
			if (i < len1) {
				d += digits[i];
			}
			if (i < len2) {
				d += another.digits[i];
			}
			r.digits.push_back(d % 10);
			carry = (d - (d % 10)) / 10;
			//  printf("carry:%d\n", carry);
		}

		if (carry > 0) {
			r.digits.push_back(carry);
		}

		return r;
	}

	bool operator==(const BCD & another) const {
		if (digits.size() != another.digits.size()) {
			return false;
		}

		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] != another.digits[i]) {
				return false;
			}
		}
		return true;
	}

	BCD reverse() {
		BCD another;
		int len = digits.size();
		int i = 0;
		while (digits[i] == 0)
			i++;
		for (int j = 0; j < len - i; j++) {
			another.digits.push_back(digits[len - j - 1]);
		}

		return another;
	}

	void print(char *tail = "") {
		int len = digits.size();
		for (int i = 0; i < len; i++) {
			printf("%d", digits[len - 1 - i]);
		}
		printf("%s", tail);
	}

	bool IsPalindromic() {
		int i = 0, j = digits.size() - 1;

		for (; i < j; i++, j--) {
			if (digits[i] != digits[j]) {
				return false;
			}

		}

		return true;
	}
};

int main() {
	char str[13];
	int k;

	scanf("%s %d", str, &k);

	BCD b(str);

	int nstep = 0;
	bool valid = false;

	while ((!b.IsPalindromic()) && nstep < k) {
		nstep++;
		b = b + b.reverse();
	}

	b.print("\n");
	printf("%d", nstep);

//  while(1);
	return 0;
}

