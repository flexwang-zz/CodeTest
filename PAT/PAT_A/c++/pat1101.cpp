/*
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N = 5 and the numbers 1, 3, 2, 4, and 5. We have:

1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 10^5). Then the next line contains N distinct positive integers no larger than 1^09. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
5
1 3 2 4 5
Sample Output:
3
1 4 5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n), a(n), b(n);
    for (int i=0; i<v.size(); i++)
        cin >> v[i];
    a[0] = v[0];
    for (int i=1; i<v.size(); i++) 
        a[i] = max(a[i-1], v[i]);
    b.back() = v.back();
    for (int i=v.size()-2; i>=0; i--)
        b[i] = min(b[i+1], v[i]);
    vector<int> result;
    for (int i=0; i<v.size(); i++)
        if (v[i] >= a[i] && v[i] <= b[i])
            result.push_back(v[i]);
    printf("%d\n", result.size());
    if (result.size() == 0) printf("\n");
    for (int i=0; i<result.size(); i++)
        printf("%d%c", result[i], i==result.size()-1?'\n':' ');
    return 0;
}