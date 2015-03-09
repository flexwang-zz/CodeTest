/*
Description

Given an N*N matrix A, whose elements are either 0 or 1. A[i, j] means the number in the i-th row and j-th column. Initially we have A[i, j] = 0 (1 <= i, j <= N). 

We can change the matrix in the following way. Given a rectangle whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2), we change all the elements in the rectangle by using "not" operation (if it is a '0' then change it into '1' otherwise change it into '0'). To maintain the information of the matrix, you are asked to write a program to receive and execute two kinds of instructions. 

1.	C x1 y1 x2 y2 (1 <= x1 <= x2 <= n, 1 <= y1 <= y2 <= n) changes the matrix by using the rectangle whose upper-left corner is (x1, y1) and lower-right corner is (x2, y2). 
2.	Q x y (1 <= x, y <= n) querys A[x, y]. 
Input

The first line of the input is an integer X (X <= 10) representing the number of test cases. The following X blocks each represents a test case. 

The first line of each block contains two numbers N and T (2 <= N <= 1000, 1 <= T <= 50000) representing the size of the matrix and the number of the instructions. The following T lines each represents an instruction having the format "Q x y" or "C x1 y1 x2 y2", which has been described above. 
Output

For each querying output one line, which has an integer representing A[x, y]. 

There is a blank line between every two continuous test cases. 
Sample Input

1
2 10
C 2 1 2 2
Q 2 2
C 2 1 2 1
Q 1 1
C 1 1 2 1
C 1 2 1 2
C 1 1 2 2
Q 1 1
C 1 1 2 1
Q 2 1
Sample Output

1
0
0
1
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
const int	max_n = 1001;
int			n, t;
ll			bit[max_n][max_n];

void init()
{
	memset(bit, 0, sizeof(bit));
}
int lowbit(int x)
{
	return x&(-x);
}
void add(int x, int y, int v)
{
	while (x <= n) {
		int tmp_y = y;
		while (tmp_y <=n ) {
			bit[x][tmp_y] += v;
			tmp_y += lowbit(tmp_y);
		}
		x += lowbit(x);
	}
}

ll sum(int x, int y)
{
	ll ans = 0;
	while (x > 0) {
		int tmp_y = y;
		while (tmp_y > 0 ) {
			ans += bit[x][tmp_y];
			tmp_y -= lowbit(tmp_y);
		}
		x -= lowbit(x);
	}
	return ans;
}


int main()
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--) {
		scanf("%d%d", &n, &t);
		init();
		for (int i=0; i<t; i++) {
			char cmd[2];
			scanf("%s", cmd);
			if (cmd[0] == 'C') {
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(x1, y1, 1);
				add(x1, y2+1, -1);
				add(x2+1, y1, -1);
				add(x2+1, y2+1, 1);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%lld\n", (sum(x, y))&1ll);
			}
		}
		printf("\n");
	}
	return 0;
}