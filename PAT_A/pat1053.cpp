#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	int w;
	vector<Node*> children;

	Node(){}
	Node(int k):w(k){}
};

bool bigger(Node *a, Node *b)
{
	return a->w > b->w;
}

void dfs(Node *, int);

int value;
vector<int> result;

int main()
{
	int nnode, nroot;

	scanf("%d %d %d", &nnode, &nroot, &value);

	vector<Node*> nodes;
	for (int i=0; i<nnode; i++) {
		int weight;

		scanf("%d", &weight);
		nodes.push_back(new Node(weight));
	}

	for (int i=0; i<nroot; i++) {
		int id, nchild;
		scanf("%d %d", &id, &nchild);

		for (int j=0; j<nchild; j++) {
			int childid;
			scanf("%d", &childid);
			nodes[id]->children.push_back(nodes[childid]);
		}

		sort(nodes[id]->children.begin(), nodes[id]->children.end(), bigger);
	}

	dfs(nodes[0], 0);
	return 0;
}

void dfs(Node *n, int v)
{
	v += n->w;
	result.push_back(n->w);
	if ( n->children.size()) {
		if ( v > value) {
			return;
		}
		else {
			for (int i=0; i<n->children.size(); i++) {
				dfs(n->children[i], v);
				result.pop_back();
			}
		}
	}
	else {
		if (v == value) {
			for (int i=0; i<result.size(); i++) {
				if (i)
				{
					printf(" ");
				}
				printf("%d", result[i]);
			}
			printf("\n");
		}
	}
}