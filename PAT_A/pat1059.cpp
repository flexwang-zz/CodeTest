/*
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *бн*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *бн*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include<stdio.h>
#include<vector>

using namespace std;

struct Node
{
	long int val;
	int time;
	Node(long int v):val(v), time(1){}
	void print()
	{
		printf("%ld", val);
		if( time > 1)
		{
			printf("^%d", time);
		}
	}
};

bool IsPrime(long int p, vector<long int>&primes)
{
	for(int i=0,size=primes.size(); i<size; i++)
	{
		if( primes[i] >= p )
		{
			return true;
		}
		if( !(p%primes[i]))
		{
			return false;
		}
	}

	primes.push_back(p);
	return true;
}

int main()
{
	long int n;
	vector<Node> nodes;
	vector<long int> primes;
	scanf("%ld", &n);

	printf("%ld=", n);

	if( n == 1)
	{
		printf("1");
		return 0;
	}
	int p = 2;
	
	while( n > 1)
	{
		if( IsPrime(p, primes) && n%p == 0)
		{
			n /= p;
			if(nodes.size() > 0 && nodes.back().val==p)
			{
				nodes.back().time++;
			}
			else
			{
				nodes.push_back(Node(p));
			}
		}
		else
		{
			p++;
		}
	}

	for( int i=0,size=nodes.size(); i<size; i++)
	{
		if( i )
		{
			printf("*");
		}
		nodes[i].print();
	}

	return 0;
}
