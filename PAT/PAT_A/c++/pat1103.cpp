/*
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12, or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that ai=bi for i<L and aL>bL

If there is no solution, simple output "Impossible".

Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mypow(int x, int y) {
    int result = 1;
    while (y--) result *= x;
    return result;
}

void helper(int target, vector<int>& v, vector<int>& ans, int cur, int p, int k) {
    if (target < 0 || v.size() > k) return;
    if (!target) {
        if (v.size() == k) {
            if (ans.size() == 0) ans = v;
            else {
                int sum_v = accumulate(v.begin(), v.end(), 0);
                int sum_ans = accumulate(ans.begin(), ans.end(), 0);
                if (sum_v > sum_ans) ans = v;
                else if (sum_v == sum_ans && v > ans) ans = v;
            }
        }
    }
    for (int i=1; i<=cur; ++i) {
        int r = mypow(i, p);
        if (r > target) break;
        v.push_back(i);
        helper(target-r, v, ans, i, p, k);
        v.pop_back();
    }
}

int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<vector<int>> result;
    vector<int> v, ans;
    helper(n, v, ans, n, p, k);
    if (ans.size() == 0) cout << "Impossible";
    else {
        cout << n << " = ";
        for (int i=0; i<ans.size(); i++) {
            if (i) cout << " + ";
            cout << ans[i] << "^" << p;
        }
    }
    return 0;

}