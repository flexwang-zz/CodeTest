/*
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 10^4 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=10^4, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

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
#include<algorithm>

using namespace std;

int main()
{
	int nnumber, value;

	scanf("%d %d", &nnumber, &value);

	vector<int> coins;

	for (int i=0; i<nnumber; i++) {
		int x;
		scanf("%d", &x);

		coins.push_back(x);
	}

	sort(coins.begin(), coins.end(), greater<int>());
	
	coins.insert(coins.begin(), 0);
	vector<vector<int>> table(nnumber+1, vector<int>(value+1, 0));
	vector<vector<bool>> path(nnumber+1, vector<bool>(value+1,false));


	for (int i=1; i<=nnumber; i++) {
		for (int j=1; j<=value; j++) {
			
			int sec = 0;
			if ((j-coins[i]) >= 0) {
				sec = table[i-1][j-coins[i]] + coins[i];
			}

			if (table[i-1][j] > sec) {
				table[i][j] = table[i-1][j];
			}
			else {
				table[i][j] = sec;
				path[i][j] = true;
			}
		}
	}

	if (table[nnumber][value] == value) {
		vector<int> result;

		while (value > 0) {
			while (!path[nnumber][value])
				nnumber--;
			result.push_back(coins[nnumber]);
			value -= coins[nnumber];
			nnumber--;
		}

		bool first = true;
		for (int i=0; i<result.size(); i++) {
			if (first)	first = false;
			else	printf(" ");
			printf("%d", result[i]);
		}
	}
	else {
		printf("No Solution");
	}

	return 0;
}