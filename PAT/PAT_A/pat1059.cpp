/*
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include<stdio.h>
#include<vector>

using namespace std;

struct node
{
	int key;
	int time;

	node(){}
	node(int k):key(k), time(1){}
};

vector<int> primes;
bool isprime(int p);

int main()
{
	int m;

	scanf("%d", &m);

	printf("%d=", m);

	if (m == 1) {
		printf("1");
		return 0;
	}
	vector<node> factors;
	int p = 2;
	while (m > 1)
	{
		while (m%p == 0) {
			if (factors.size())
			{
				if (factors.back().key == p) {
					factors.back().time ++;
				}
				else {
					factors.push_back(node(p));
				}
			}
			else
			{
				factors.push_back(node(p));
			}

			m /= p;
		}

		while (!isprime(++p))
			;
	}

	for (int i=0; i<factors.size(); i++) {
	
		if (i)	printf("*");

		printf("%d", factors[i].key);

		if (factors[i].time > 1) {
			printf("^%d", factors[i].time);
		}
	}
	return 0;
}

bool isprime(int p)
{
	for (int i=0; i<primes.size(); i++) {
		if (p!=primes[i] && p%primes[i] == 0) {
			return false;
		}
	}
	primes.push_back(p);
	
	return true;
}
