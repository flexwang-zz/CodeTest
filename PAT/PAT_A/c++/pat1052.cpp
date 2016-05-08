/*
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 10^5) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-105, 10^5], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Node
{
public:
	int address;
	int val;
	int nextaddress;

	Node(int add, int v, int next):address(add), val(v), nextaddress(next){}

	bool operator<(const Node&node) const
	{
		return val<node.val;
	}

};


int main()
{
	int nnode, head;

	scanf("%d %d", &nnode, &head);

	vector<Node*> table(100001, NULL);

	for( int i=0; i<nnode; i++)
	{
		int addr, val, nextaddr;
		scanf("%d %d %d", &addr, &val, &nextaddr);
		
		table[addr] = new Node(addr, val, nextaddr);

	}

	vector<Node> nodes;
	
	while(head > 0 && table[head] )
	{
		nodes.push_back(*table[head]);
		head = table[head]->nextaddress;
	}

	if( nodes.size() <= 0)
	{
		printf("0 -1");
		return 0;
	}

	sort(nodes.begin(), nodes.end());

	printf("%d %05d\n", nodes.size(), nodes[0].address);

	for(int i=0, size=nodes.size(); i<size; i++)
	{
		if( i != (size-1))
		{
			printf("%05d %d %05d\n", nodes[i].address, nodes[i].val, nodes[i+1].address);
		}
		else
		{
			printf("%05d %d -1\n", nodes[i].address, nodes[i].val);
		}
	}

	return 0;
}