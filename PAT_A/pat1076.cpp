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