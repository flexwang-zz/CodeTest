/*
 ﻿Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800x600), you are supposed to point out the strictly dominant color.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (<=800) and N (<=600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0, 224). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, simply print the dominant color in a line.
 Sample Input:
 5 3
 0 0 255 16777215 24
 24 24 0 0 24
 24 0 24 24 24

 Sample Output:
 24

 */

#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main() {
	int m, n;

	cin >> m >> n;

	int a = -1;
	int time = 0;
	int discard = 0;

	for (int i = 0; i < m * n; i++) {
		int x;

		scanf("%d", &x);

		if (a < 0) {
			a = x;
			time = 1;
		} else {
			if (a != x) {
				time--;
				discard += 2;
				if (time <= 0) {
					a = -1;
				}
			} else {
				time++;
				if (time > (m * n - discard) / 2) {
					break;
				}
			}
		}
	}

	cout << a;
	return 0;
}

