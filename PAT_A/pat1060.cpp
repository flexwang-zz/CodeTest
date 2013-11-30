/*
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*105 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

Input Specification:

Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.

Output Specification:

For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.

Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

void foo(vector<char> &v, int &exp, char *s, int n)
{
	v.push_back('0');
	v.push_back('.');
	bool meetdot = false;
	int nsig = 0;
	for( int i=0,size=strlen(s); i<size; i++)
	{
		char ch = s[i];

		if( ch == '.')
		{
			meetdot = true;
		}
		else
		{
			if( !meetdot)
			{
				if( exp <= 0)
				{
					if( ch != '0')
					{
						v.push_back(ch);
						nsig ++;
						exp++;
					}
				}
				else
				{
					v.push_back(ch);
					nsig ++;
					exp++;
				}
			}
			else
			{
				if( nsig <= 0)
				{
					if( ch != '0')
					{
						v.push_back(ch);
						nsig ++;
					}
					else
					{
						exp --;
					}
				}
				else
				{
					v.push_back(ch);
					nsig ++;
				}
			}
		}
		if( nsig >= n && meetdot)
		{
			break;
		}
	}

	if( v.size() <= 2)
	{
		exp = 0;
	}

	for( int i=2; i<n+2; i++)
	{
		if( i>=v.size())
		{
			v.push_back('0');
		}
	}

	
}

bool issame(vector<char>v1, vector<char>v2, int n)
{
	for( int i=2; i<n+2; i++)
	{
		if( v1[i] != v2[i])
		{
			return false;
		}
	}

	return true;
}

void print(vector<char> v, int n, int exp)
{
	printf("%c%c", v[0], v[1]);
	for( int i=2; i<n+2; i++)
	{
		printf("%c", v[i]);
	}
	printf("*10^%d", exp);
}

int main()
{
	int n;
	char s1[150], s2[150];
	vector<char> v1, v2;
	int exp1 = 0;
	int exp2 = 0;

	scanf("%d %s %s", &n, s1, s2);
	
	
	

	foo(v1, exp1, s1, n);
	foo(v2, exp2, s2, n);

	if( exp1 != exp2 || !issame(v1, v2, n))
	{
		printf("NO ");
		print(v1, n, exp1);
		printf(" ");
		print(v2, n, exp2);
		
	}
	else
	{
		printf("YES ");
		print(v1, n, exp1);
	}

	return 0;
}