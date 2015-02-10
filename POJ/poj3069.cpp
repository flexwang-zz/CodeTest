/*
Description

Saruman the White must lead his army along a straight path from Isengard to Helm’s Deep. To keep track of his forces, Saruman distributes seeing stones, known as palantirs, among the troops. Each palantir has a maximum effective range of R units, and must be carried by some troop in the army (i.e., palantirs are not allowed to “free float” in mid-air). Help Saruman take control of Middle Earth by determining the minimum number of palantirs needed for Saruman to ensure that each of his minions is within R units of some palantir.

Input

The input test file will contain multiple cases. Each test case begins with a single line containing an integer R, the maximum effective range of all palantirs (where 0 ≤ R ≤ 1000), and an integer n, the number of troops in Saruman’s army (where 1 ≤ n ≤ 1000). The next line contains n integers, indicating the positions x1, …, xn of each troop (where 0 ≤ xi ≤ 1000). The end-of-file is marked by a test case with R = n = −1.

Output

For each test case, print a single integer indicating the minimum number of palantirs needed.

Sample Input

0 3
10 20 20
10 7
70 30 1 7 15 20 50
-1 -1
Sample Output

2
4
Hint

In the first test case, Saruman may place a palantir at positions 10 and 20. Here, note that a single palantir with range 0 can cover both of the troops at position 20.

In the second test case, Saruman can place palantirs at position 7 (covering troops at 1, 7, and 15), position 20 (covering positions 20 and 30), position 50, and position 70. Here, note that palantirs must be distributed among troops and are not allowed to “free float.” Thus, Saruman cannot place a palantir at position 60 to cover the troops at positions 50 and 70.
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int         n, r;
vector<int> xs;

int main()
{
    for (;;) {
        scanf("%d %d", &r, &n);
        if (n < 0)  break;
        xs.clear();
        for (int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            xs.push_back(x);
        }

        sort(&xs[0], &xs[0]+n);

        int ans = 0;

        int left = xs[0];
        int x0 = 0;
        while (true) {
            for (;x0+1<n && xs[x0+1]-left<=r; x0++);
            ans ++;
            left = xs[x0];
            if (x0 == n-1)    break;
            for (;x0+1<n && xs[x0+1]-left<=r; x0++);
            if (x0 == n-1)    break;
            x0++;
            left = xs[x0];
        }

        printf("%d\n", ans);
    }
}
