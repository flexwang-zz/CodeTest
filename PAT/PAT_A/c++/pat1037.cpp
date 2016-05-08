/*
 ﻿The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!
 For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} (in Mars dollars M$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; coupon 2 to product 2 to get M$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.
 Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. Then the next line contains the number of products NP, followed by a line with NP product values. Here 1<= NC, NP <= 10^5, and it is guaranteed that all the numbers will not exceed 230.
 Output Specification:
 For each test case, simply print in a line the maximum amount of money you can get back.
 Sample Input:
 4
 1 2 4 -1
 4
 7 6 -2 -3

 Sample Output:
 43
 */

#include<stdio.h>
#include<vector>
#include<algorithm>

bool lessthan(const long int &a, const long int &b) {
	return a > b;
}

using namespace std;

class BCD {
public:
	vector<char> digits;

	BCD() {
	}

	BCD(const BCD &bcd) {
		digits = bcd.digits;
	}
	BCD(int value) {
		do {
			digits.push_back('0' + value % 10);
			value /= 10;
		} while (value > 0);
	}

	void print() {
		int len = digits.size();
		for (int i = 0; i < len; i++) {
			printf("%c", digits[len - 1 - i]);
		}
	}

	BCD operator*(int value) {
		BCD result;
		vector<char>::iterator iter;

		iter = digits.begin();

		int carry = 0;
		while (iter != digits.begin()) {
			int u = ((*iter) - '0') * value + carry;
			result.digits.push_back(u % 10 + '0');
			carry = u / 10;
		}

		return result;
	}

	BCD operator+(BCD& bcd) {
		BCD result;
		vector<char>::iterator iter1;
		vector<char>::iterator iter2;

		iter1 = digits.begin();
		iter2 = bcd.digits.begin();

		int carry = 0;

		while (iter1 != digits.end() || iter2 != bcd.digits.end() || carry > 0) {
			int u = carry;

			if (iter1 != digits.end()) {
				u += *iter1 - '0';
				iter1++;
			}

			if (iter2 != bcd.digits.end()) {
				u += *iter2 - '0';
				iter2++;
			}

			result.digits.push_back(u % 10 + '0');
			carry = u / 10;
		}

		return result;
	}

	BCD& operator+=(BCD& bcd) {
		vector<char>::iterator iter1;
		vector<char>::iterator iter2;

		vector<char> newdigits;

		iter1 = (*this).digits.begin();
		iter2 = bcd.digits.begin();

		int carry = 0;

		while (iter1 != digits.end() || iter2 != bcd.digits.end()) {
			int u = carry;

			if (iter1 != digits.end()) {
				u += *iter1 - '0';
				iter1++;
			}

			if (iter2 != bcd.digits.end()) {
				u += *iter2 - '0';
				iter2++;
			}

			newdigits.push_back(u % 10 + '0');
			carry = u / 10;
		}

		digits = newdigits;

		return *this;
	}
};

using namespace std;

int main() {

	int ncoupon, nproduct;
	vector<long int> coupons;
	vector<long int> bcoupons;
	vector<long int> products;
	vector<long int> bonuses;

	scanf("%d", &ncoupon);

	for (int i = 0; i < ncoupon; i++) {
		long int coupon;
		scanf("%ld", &coupon);

		if (coupon > 0) {
			coupons.push_back(coupon);
		} else {
			bcoupons.push_back(-coupon);
		}
	}

	scanf("%d", &nproduct);

	for (int i = 0; i < nproduct; i++) {
		long int product;
		scanf("%ld", &product);

		if (product > 0) {
			products.push_back(product);
		} else {
			bonuses.push_back(-product);
		}
	}

	sort(coupons.begin(), coupons.end(), lessthan);
	sort(bcoupons.begin(), bcoupons.end(), lessthan);

	sort(products.begin(), products.end(), lessthan);
	sort(bonuses.begin(), bonuses.end(), lessthan);

	BCD money(0);
//  printf("finish sorting\n");
	vector<long int>::iterator iter1, iter2;

	iter1 = coupons.begin();
	iter2 = products.begin();

	while (iter1 != coupons.end() && iter2 != products.end()) {
		long long int s = (long long int) (*iter1) * (long long int) (*iter2);
		//printf("%d\n", s);
		BCD bcd(s);
		money = money + bcd;
		iter1++;
		iter2++;
	}

	iter1 = bcoupons.begin();
	iter2 = bonuses.begin();

	while (iter1 != bcoupons.end() && iter2 != bonuses.end()) {
		long long int s = (((long long int) *iter1))
				* (((long long int) *iter2));
		//  printf("%d\n", s);
		BCD bcd(s);
		money = money + bcd;
		iter1++;
		iter2++;
	}

//  printf("%lld", money);
	money.print();

//  system("pause");
	return 0;
}

