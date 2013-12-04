/*
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#include<list>

using namespace std;

struct StackNode
{
	int key;
	int mid;
	int offset;

	StackNode(){}
	StackNode(int k, int m, int o):key(k), mid(m), offset(o){}
};

class Stack
{
public:
	vector<int> table;
	vector<StackNode> v;

	Stack()
	{
		table = vector<int>(100001,0);
	}

	void Push(int key)
	{
		table[key]++;

		int size = v.size();
		if( v.size())
		{
			int mid = v.back().mid;
			int offset = v.back().offset;
			if( size%2 && key<mid)
			{
				offset--;

				if( offset < 0)
				{
					for( int i=mid-1; i>0; i--)
					{
						if( table[i] > 0)
						{
							mid = i;
							offset = table[i]-1;
							break;
						}
					}
				}
			}
			else if( size%2==0 && key>=mid)
			{
				offset++;
				if( offset >= table[mid])
				{
					for( int i=mid+1; i<100001; i++)
					{
						if( table[i] > 0)
						{
							mid = i;
							offset = 0;
							break;
						}
					}
				}
			}
			v.push_back(StackNode(key, mid, offset));
		}
		else
		{
			v.push_back(StackNode(key, key, 0));
		}
	}
	//void Push(int key)
	//{
	//	list<int>::iterator iter;

	//	for( iter=keys.begin(); iter!=keys.end(); iter++)
	//	{
	//		if( *iter >= key)
	//		{
	//			break;
	//		}
	//	}

	//	keys.insert(iter, key);
	//	
	//	iter--;	//move to the newly inserted position

	//	list<int>::iterator mid;

	//	int size = v.size();
	//	if( size )
	//	{
	//		mid = v.back().mid;
	//		if( size%2 && key<*mid)
	//		{
	//			mid--;	
	//		}
	//		else if( size%2==0 && key>*mid)
	//		{
	//			mid++;
	//		}
	//	}
	//	else
	//	{
	//		mid = iter;
	//	}

	//	v.push_back(StackNode(iter, mid));
	//}

	void Pop()
	{
		if( v.size() <= 0)
		{
			printf("Invalid\n");
			return;
		}		

		int key = v.back().key;
		printf("%d\n", key);
		table[key] --;
		v.pop_back();
	}

	void Peek()
	{	
		if( v.size() <= 0)
		{
			printf("Invalid\n");
			return;
		}
		printf("%d\n", v.back().mid);
	}

};

int main()
{
	Stack stack;

	int nop;
	char op[11]; 
	scanf("%d", &nop);

	for(int i=0; i<nop; i++)
	{
		scanf("%s", op);

		if( strcmp(op, "Push") == 0)
		{
			int key;

			scanf("%d", &key);

			stack.Push(key);
		}
		else if(strcmp(op, "Pop") == 0)
		{
			stack.Pop();
		}
		else
		{
			stack.Peek();
		}
	}
	return 0;
} 
