/*
 ﻿Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=10^5, the total number of coins) and M(<=10^3, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output "No Solution" instead.
 Sample Input 1:
 8 15
 1 2 8 7 2 4 11 15

 Sample Output 1:
 4 11

 Sample Input 2:
 7 14
 1 8 7 2 4 11 15

 Sample Output 2:
 No Solution
 */
#include <unordered_map>
#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> um;
    for (int i=0; i<n; ++i) {
        int x;
        cin >> x;
        um[x]++;
    }
    pair<int,int> res(INT_MAX, INT_MAX);
    for (auto p : um)
        if (p.second >= 2 && p.first*2 == m)
            res = min(res, make_pair(p.first, p.first));
        else if (um.find(m-p.first) != um.end() && p.first*2 < m)
            res = min(res, make_pair(p.first, m-p.first));
    if (res.first == INT_MAX) cout << "No Solution" << endl;
    else cout << res.first << " " << res.second << endl;
    return 0;
}