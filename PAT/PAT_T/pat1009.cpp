/*
Given a list of N integers A1, A2, A3,...AN, there's a famous problem to count the number of inversions in it. An inversion is defined as a pair of indices i < j such that Ai > Aj.

Now we have a new challenging problem. You are supposed to count the number of triple inversions in it. As you may guess, a triple inversion is defined as a triple of indices i < j < k such that Ai > Aj > Ak. For example, in the list {5, 1, 4, 3, 2} there are 4 triple inversions, namely (5,4,3), (5,4,2), (5,3,2) and (4,3,2). To simplify the problem, the list A is given as a permutation of integers from 1 to N.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N in [3, 10^5]. The second line contains a permutation of integers from 1 to N and each of the integer is separated by a single space.

Output Specification:

For each case, print in a line the number of triple inversions in the list.

Sample Input:
22
1 2 3 4 5 16 6 7 8 9 10 19 11 12 14 15 17 18 21 22 20 13
Sample Output:
8
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
    long long v, n, pos;
};

const int max_n = 100001;
int n;
int a[max_n];
long long cnt1[max_n], cnt2[max_n];

void merge_sort(vector<P> &v) {
    if (v.size() < 2) return;
    vector<P> v1(v.begin(), v.begin()+v.size()/2);
    vector<P> v2(v.begin()+v.size()/2, v.end());
    merge_sort(v1), merge_sort(v2);
    for (int i=0,j=0,k=0; k<v.size();) 
        if (i == v1.size()) v[k++] = v2[j++];
        else if (j == v2.size() || v1[i].v < v2[j].v) v[k++] = v1[i++];
        else {
            v2[j].n += v1.size()-i;
            v[k++] = v2[j++];
        }
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    vector<P> v(n);
    for (int i=0; i<n; ++i)
        v[i] = {a[i], 0, i};
    merge_sort(v);
    for (int i=0; i<n; ++i) {
        cnt1[v[i].pos] = v[i].n;
        v[i] = {-a[n-i-1], 0, n-i-1};
    }
    merge_sort(v);
    for (int i=0; i<n; ++i) 
        cnt2[v[i].pos] = v[i].n;
    long long res = 0;
    for (int i=0; i<n; ++i)
        res += cnt1[i]*cnt2[i];
    printf("%lld\n", res);
    return 0;
}