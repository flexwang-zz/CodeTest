/*
Description

Suppose that the fourth generation mobile phone base stations in the Tampere area operate as follows. The area is divided into squares. The squares form an S * S matrix with the rows and columns numbered from 0 to S-1. Each square contains a base station. The number of active mobile phones inside a square can change because a phone is moved from a square to another or a phone is switched on or off. At times, each base station reports the change in the number of active phones to the main base station along with the row and the column of the matrix. 

Write a program, which receives these reports and answers queries about the current total number of active mobile phones in any rectangle-shaped area. 
Input

The input is read from standard input as integers and the answers to the queries are written to standard output as integers. The input is encoded as follows. Each input comes on a separate line, and consists of one instruction integer and a number of parameter integers according to the following table. 


The values will always be in range, so there is no need to check them. In particular, if A is negative, it can be assumed that it will not reduce the square value below zero. The indexing starts at 0, e.g. for a table of size 4 * 4, we have 0 <= X <= 3 and 0 <= Y <= 3. 

Table size: 1 * 1 <= S * S <= 1024 * 1024 
Cell value V at any time: 0 <= V <= 32767 
Update amount: -32768 <= A <= 32767 
No of instructions in input: 3 <= U <= 60002 
Maximum number of phones in the whole table: M= 2^30 
Output

Your program should not answer anything to lines with an instruction other than 2. If the instruction is 2, then your program is expected to answer the query by writing the answer as a single line containing a single integer to standard output.
Sample Input

0 4
1 1 2 3
2 0 0 2 2 
1 1 1 2
1 1 2 -1
2 1 1 2 3 
3
Sample Output

3
4
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
const int	max_n = 1024+2;
ll			bit[max_n][max_n];
int			s;

void	init()
{
	memset(bit, 0, sizeof(bit));
}

int	lowbit(int x)
{
	return x&(-x);
}

void	add(int x, int y, int a)
{
	while (x <= s) {
		int tmp_y = y;
		while (tmp_y <= s) {
			bit[x][tmp_y] += a;
			tmp_y += lowbit(tmp_y);
		}
		x += lowbit(x);
	}
}
ll	sum(int x, int y)
{
	ll ans = 0;
	while (x > 0) {
		int tmp_y = y;
		while (tmp_y > 0) {
			ans += bit[x][tmp_y];
			tmp_y -= lowbit(tmp_y);
		}
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	for (;;) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 3)
			break;
		else if (cmd == 0) {
			scanf("%d", &s);
			init();
		}
		else if (cmd == 1) {
			int x, y, a;
			scanf("%d%d%d", &x, &y, &a);
			add(x+1, y+1, a);
		}
		else if (cmd == 2) {
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%lld\n", sum(x2+1, y2+1)-sum(x1, y2+1)-sum(x2+1, y1) + sum(x1, y1));
		}
	}
	return 0;
}