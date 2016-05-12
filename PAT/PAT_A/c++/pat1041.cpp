/*
 ﻿Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 10^4]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.
 Input Specification:
 Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=10^5) and then followed by N bets. The numbers are separated by a space.
 Output Specification:
 For each test case, print the winning number in a line. If there is no winner, print "None" instead.
 Sample Input 1:
 7 5 31 5 88 67 88 17

 Sample Output 1:
 31

 Sample Input 2:
 5 888 666 666 888 888

 Sample Output 2:
 None

 */
#include <iostream>
#include <utility>

using namespace std;
const int max_n = 100001;
pair<int,int> tab[max_n];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		tab[x].first++;
		tab[x].second = i;
	}
	int res = -1, id = max_n;
	for (int i=1; i<max_n; ++i)
		if (tab[i].first == 1 && tab[i].second < id)
			res = i, id = tab[i].second;
	if (res < 0) cout << "None" << endl;
	else cout << res << endl;
	return 0;
}