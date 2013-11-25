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

#include<stdio.h>

class Node {
public:
	float a;
	int n;
	Node* next;

	Node(float aa, int nn) :
			a(aa), n(nn), next(NULL) {
	}
};

class Poly {
public:
	int len;
	Node* head;
	Poly() :
			len(0), head(NULL) {
	}
	void print() {
		printf("%d ", len);
		Node* cur = head;
		for (int i = 0; i < len; i++) {
			printf("%d %.1f", cur->n, cur->a);
			if (i != (len - 1))
				printf(" ");
			cur = cur->next;
		}
		if (len <= 0)
			printf("0 0");
	}
	void insert(float a, int n) {
		if (!head) {
			head = new Node(a, n);
			len++;
		} else {
			Node* cur = head;
			Node* last = NULL;
			while (true) {
				if (!cur) {
					last->next = new Node(a, n);
					len++;
					break;
				}
				if (cur->n == n) {
					cur->a += a;
					if (cur->a == 0) {
						if (last) {
							last->next = cur->next;
							delete cur;
						} else {
							delete cur;
							cur = NULL;
						}
						len--;
					}
					break;
				}
				if (cur->n < n) {
					if (last) {
						last->next = new Node(a, n);
						last->next->next = cur;
					} else {
						head = new Node(a, n);
						head->next = cur;
					}
					len++;
					break;
				}

				last = cur;
				cur = cur->next;
			}
		}
	}
};

int main() {
	int N;
	scanf("%d", &N);
	Poly p1, p2;
	for (int i = 0; i < N; i++) {
		int n;
		float a;
		scanf("%d %f", &n, &a);
		p1.insert(a, n);
	}
	int N2;
	scanf("%d", &N2);
	for (int i = 0; i < N2; i++) {
		int n;
		float a;
		scanf("%d %f", &n, &a);
		Node* cur = p1.head;
		for (int j = 0; j < N; j++) {
			p2.insert(cur->a * a, cur->n + n);
			cur = cur->next;
		}
	}

	p2.print();

	return 0;
}

