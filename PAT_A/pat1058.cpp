/*
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char s1[30], s2[30];

	scanf("%s %s", s1, s2);

	int index1[3], index2[3];

	int i=0;
	
	index1[0] = 0;
	int index = 1;
	while(true)
	{
		char ch = s1[i];

		if( ch == '.' )
		{
			s1[i] = '\0';
			index1[index++] = i+1;
		}
		else if( ch == '\0' )
		{
			break;
		}
		i++;
	}

	index2[0] = 0;
	index = 1;
	i = 0;
	while(true)
	{
		char ch = s2[i];

		if( ch == '.' )
		{
			s2[i] = '\0';
			index2[index++] = i+1;
		}
		else if( ch == '\0' )
		{
			break;
		}
		i++;
	}

	int a[3] = {0,0,0};

	for(int i=0; i<3; i++)
	{
		a[i] = atoi(s1+index1[i]) + atoi(s2+index2[i]);
	}

	a[1] += a[2]/29;
	
	a[2] %= 29;

	a[0] += a[1]/17;

	a[1] %= 17;

	printf("%d.%d.%d", a[0], a[1], a[2]);

	return 0;
}