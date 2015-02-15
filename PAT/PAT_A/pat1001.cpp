/*
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/

#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	a += b;

	if( a < 0)
	{
		printf("-");
		a = -a;
	}

	vector<int> digits;
	do
	{
		digits.insert(digits.begin(), a%10);
		a /= 10;
	}while(a > 0);

	for( int i=0, size=digits.size(); i<size; i++)
	{
		if(  (size-i)%3 == 0 && i)
		{
			printf(",");
		}
		printf("%d", digits[i]);
	}

	return 0;
}