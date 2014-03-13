/*
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/
#include<stdio.h>
#include<vector>

using namespace std;

struct node {
	vector<int> followers;
};

int main()
{
	int nuser, nlevel;

	scanf("%d %d", &nuser, &nlevel);

	vector<node> nodes(nuser+1);

	for (int i=1; i<=nuser; i++) {
		int nf;

		scanf("%d", &nf);

		for (int j=0; j<nf; j++) {
			int id;
			scanf("%d", &id);

			nodes[id].followers.push_back(i);
		}
	}

	int kproblem;

	scanf("%d", &kproblem);

	for (int p=0; p<kproblem; p++) {
		int problem;

		scanf("%d", &problem);
		vector<bool> visited(nuser+1, false);
		visited[problem] = true;
		vector<int> thislayer;
		thislayer.push_back(problem);
		int level = 0;
		int nfollower = 0;
		while (thislayer.size() && level++ < nlevel) {
			vector<int> nextlayer;

			for (int i=0; i<thislayer.size(); i++) {
				node user = nodes[thislayer[i]];

				for (int j=0; j<user.followers.size(); j++) {
					if (!visited[user.followers[j]]) {
						nextlayer.push_back(user.followers[j]);
						visited[user.followers[j]] = true;
						nfollower ++;
					}
				}
			}

			thislayer = nextlayer;
		}

		printf("%d\n", nfollower);
	}
	return 0;
}