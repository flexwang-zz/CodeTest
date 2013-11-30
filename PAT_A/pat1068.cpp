/*
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
*/
#include<stdio.h>
#include<vector>

using namespace std;

#define min(a,b) (a<b)?a:b

class Node
{
public:
	vector<int> v;
	int remain;
	int time;

	bool operator<(const Node&node) const
	{
		int size = min(v.size(), node.v.size());

		for(int i=0; i<size; i++)
		{
			if( v[i] < node.v[i])
			{
				return true;
			}
			else if( v[i] > node.v[i])
			{
				return false;
			}
		}
	}
};




int main()
{
	int n, money;

	scanf("%d %d", &n, &money);

	vector<int> bucket(money+1);
	for( int i=0; i<=money; i++)
	{
		bucket[i] = 0;
	}

	for( int i=0; i<n; i++)
	{
		int m;
		scanf("%d", &m);

		if( m <= money)
		{
			bucket[m] ++;
		}
	}

	vector<Node> nodes;
	Node result;
	result.v.push_back(money+1);

	Node node;
	node.remain = money;
	node.v.push_back(0);
	node.time = 0;

	nodes.push_back(node);

	while(nodes.size())
	{
		vector<Node> nextlayer;

		for(int i=0,size=nodes.size(); i<size; i++)
		{
			int remain = nodes[i].remain;

			if( result < nodes[i])
			{
				continue;
			}
			else if( remain <= 0)
			{
				result = nodes[i];
				continue;
			}

			int start = nodes[i].v.back();

			if( bucket[start]-nodes[i].time > 0 && start <= remain)
			{
				Node node = nodes[i];
				node.time ++;
				node.v.push_back(start);
				node.remain = remain-start;
				nextlayer.push_back(node);
			}

			for(int j=start+1; j<=remain; j++)
			{
				if( bucket[j] > 0)
				{
					Node node = nodes[i];
					node.v.push_back(j);
					node.remain -= j;
					node.time = 1;
					nextlayer.push_back(node);
				}
			}
		}

		nodes = nextlayer;
	}

	if( !result.v[0] )
	{
		for( int i=1; i<result.v.size(); i++)
		{
			if( i>1)
			{
				printf(" ");
			}
			printf("%d", result.v[i]);
		}
	}
	else
	{
		printf("No Solution");
	}

	return 0;
}