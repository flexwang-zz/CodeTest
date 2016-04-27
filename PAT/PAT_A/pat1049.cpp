/*
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (<=230).

Output Specification:

For each test case, print the number of 1's in one line.

Sample Input:
12
Sample Output:
5
*/
#include <stdio.h>

int f(int n) 
{
	if (n < 10) return n?1:0;
	int p = 1;
	while (n/p >= 10)
		p *= 10;
	int d = n / p;
	int a = d*f(p-1);
	int b = d==1?(n%p+1):p;
	int c = n%p;
	return a + b + f(c);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
}