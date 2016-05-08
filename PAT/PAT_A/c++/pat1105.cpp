/*
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive integers to be filled into the spiral matrix. All the numbers are no more than 10^4. The numbers in a line are separated by spaces.

Output Specification:

For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93
Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
int b[9999][100];
void print(int *a, int m, int n)
{
    int dj[] = {0, 1, 0, -1};
    int dk[] = {1, 0, -1, 0};
    for (int i=m*n-1,j=0,k=0,dir=0; i>=0; --i) {
        b[j][k] = a[i];
        int j0 = dj[dir] + j;
        int k0 = dk[dir] + k;
        if (j0 < 0 || j0 >= m || k0 < 0 || k0 >= n || b[j0][k0])
            dir = (dir+1)%4;
        j += dj[dir];
        k += dk[dir];
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            printf("%d%c", b[i][j], j==n-1?'\n':' ');
}


int main()
{
    int a[10000];
    int M, m, n;
    scanf("%d", &M);
    for (int i=0; i<M; ++i)
        scanf("%d", &a[i]);
    sort(a, a+M);
    for (n=sqrt(M); M%n; --n);
    m = M/n;
    print(a, m, n);
    return 0;
}
