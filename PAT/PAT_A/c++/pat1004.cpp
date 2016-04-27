/*
﻿A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02

Sample Output
0 1
*/



#include<stdio.h>

class Node
{
public:
	Node(int Id)
	{
		ID = Id;
		nchild = 0;
	}
 
	void Insert(int childId)
	{
		childID[nchild++] = childId;
	}
 
	int ID;
	int nchild;
	int childID[100];
};

int main()
{
	int NNode, NFather;
	Node* nodes[100];
	Node* root = NULL;
 
	scanf("%d %d", &NNode, &NFather);
 
 
	for(int i=0; i<NFather; i++)
	{
		int ID, nchild;
		scanf("%d %d", &ID, &nchild);
		nodes[i] = new Node(ID);
   
   
		if( ID == 1)
		{  
			root = nodes[i];
		}
   
		for( int j=0; j<nchild; j++)
		{  
			int childid;
			scanf("%d", &childid);
			nodes[i]->Insert(childid);
		}
	}
 
	Node* curlayer[100];
	int cursize;
 

	cursize = 1;
	curlayer[0] = root;

	int cursize2;
	Node* curlayer2[100];
   
	bool firstprint = true;
 
	while(cursize>0)
	{
	   	cursize2 = 0;
		int nleaf = 0;
		for(int i=0; i < cursize; i++)
		{
			if( curlayer[i] == NULL )
			{
				nleaf ++;
			}
			else
			{
			   
				for( int j=0; j<curlayer[i]->nchild; j++)
				{
					bool found = false;
				 	for(int k=0; k<NFather; k++)
				 	{
						if( nodes[k]->ID == curlayer[i]->childID[j])
				   		{
							found = true;
							 curlayer2[cursize2++] = nodes[k];
							 break;
				   		}
					}
					if( !found)
					{
						curlayer2[cursize2++] = NULL;
					}
			   	}
			}
		}
		if( firstprint )
		{
			firstprint = false;
		}
		else
		{
			printf(" ");
		}
		   
		printf("%d", nleaf);
		   
		cursize = cursize2;

		for( int i=0; i<cursize2; i++)
		{
			curlayer[i] = curlayer2[i];
		}
 	}
 

	return 0;
}
