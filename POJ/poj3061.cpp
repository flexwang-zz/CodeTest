/*
Description

A sequence of N positive integers (10 < N < 100 000), each of them less than or equal 10000, and a positive integer S (S < 100 000 000) are given. Write a program to find the minimal length of the subsequence of consecutive elements of the sequence, the sum of which is greater than or equal to S.
Input

The first line is the number of test cases. For each test case the program has to read the numbers N and S, separated by an interval, from the first line. The numbers of the sequence are given in the second line of the test case, separated by intervals. The input will finish with the end of file.
Output

For each the case the program has to print the result on separate line of the output file.if no answer, print 0.
Sample Input

2
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
Sample Output

2
3
*/
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ns;
int         n, S;
int         ncase;
int main()
{
    scanf("%d", &ncase);

    for (int ic=0; ic<ncase; ic++) {
        scanf("%d %d", &n, &S);
        ns.resize(n);

        for (int i=0; i<n; i++)
            scanf("%d", &ns[i]);

        int ans = 0;
        int sum = 0;
        int s = 0, t = 0;

        for(;;) {
            while (sum < S && t <= n-1) {
                sum += ns[t++];
            }
            while (sum >= S && s <= n-1) {
                if (ans == 0 || ans > t-s)
                    ans = t - s;
                sum -= ns[s++];
            }
            if (t > n-1)
                break;
        }

        printf("%d\n", ans);
    }
    return 0;
}