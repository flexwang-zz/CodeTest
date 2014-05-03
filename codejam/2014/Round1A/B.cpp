#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Node{
	vector<int> children;
};

vector<Node> nodes;
vector<bool> available;
inline int bfs(int n) {
	vector<int> children;

	for (int i=0; i<nodes[n].children.size(); i++) {
		int id = nodes[n].children[i];

		if (available[id]) {
			children.push_back(id);
		}
	}

	if (children.size() < 2) {
		return 1;
	}

	vector<int> ndelete;

	for (int i=0; i<children.size(); i++) {
		int id = children[i];

		available[id] = false;
		ndelete.push_back(bfs(id));
		available[id] = true;
	}

	sort(ndelete.begin(), ndelete.end(), greater<int>());

	return ndelete[0]+ndelete[1]+1;
}

int main()
{
	int T;

	cin >> T;

	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int nnode;

		cin >> nnode;
		
		nodes = vector<Node>(nnode);
		
		for (int i=0; i<nnode-1; i++) {
			int a, b;

			cin >> a >> b;
			nodes[a-1].children.push_back(b-1);
			nodes[b-1].children.push_back(a-1);
		}

		int nreserve = 0;
		for (int i=0; i<nnode; i++) {
			available = vector<bool>(nnode, true);
			available[i] = false;
			int x = bfs(i);
			if (x > nreserve) {
				nreserve = x;
			}
			
		}

		cout << nnode-nreserve << endl;
	}
}