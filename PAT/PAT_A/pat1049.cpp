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

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int atoi(char*str, int start, int end)
{
	int result = 0;

	for( int i=start; i<=end; i++)
	{
		result = result*10 + str[i]-'0';
	}

	return result;
}

int main()
{
	char str[30];

	scanf("%s", str);

	int n = 0;
	int len = strlen(str);


	for( int i=0; i<len; i++)
	{
		if( str[i] == '1' )
		{
			n += atoi(str, i+1, len-1)+1;
		}
		else if( str[i] == '0' )
		{
		}
		else
		{
			n += pow(10.f, len-i-1);
		}

		n += (atoi(str, 0, i-1))*pow(10.f, len-i-1);
	}

	printf("%d", n);
	return 0;
}