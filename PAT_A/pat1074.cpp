#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int value;
	int next;

	node(){}
	node(int n, int v):next(n), value(v){}
};

void reverse(vector<int>&, int, int);

int main()
{
	int head, nnode, k;

	scanf("%d %d %d", &head, &nnode, &k);

	vector<node> nodes(100001);
	for (int i=0; i<nnode; i++) {
		int key, value, next;

		scanf("%d %d %d", &key, &value, &next);

		nodes[key].value = value;
		nodes[key].next = next;
	}

	vector<int> keys;

	int p = head;

	while (p >= 0) {
		keys.push_back(p);
		p = nodes[p].next;
	}

	int size = keys.size();

	int nrun = size/k;

	for (int i=0; i<nrun; i++) {
		reverse(keys, k*i, k*(i+1)-1);
	}

	for (int i=0; i<size; i++) {
		printf("%05d %d ", keys[i], nodes[keys[i]].value);

		if (i == (size-1)) {
			printf("-1\n");
		}
		else {
			printf("%05d\n", keys[i+1]);
		}
	}

	return 0;
}

void reverse(vector<int>&keys, int start, int end) {
	
	while (start < end) {
		int temp = keys[start];
		keys[start] = keys[end];
		keys[end] = temp;

		start++;
		end--;
	}
}