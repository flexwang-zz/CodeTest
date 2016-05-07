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
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <stack>
#include <string>

using namespace std;

class Stack{
public:
	void push(int v) {
		if (m1.empty() || v <= *m1.rbegin())
			m1.insert(v);
		else
			m2.insert(v);
		adjust();
		st.push(v);
	}
	int pop() {
		if (st.empty()) return -1;
		int p = st.top();
		st.pop();
		auto pt = m1.find(p);
		if (pt != m1.end())
			m1.erase(pt);
		else 
			m2.erase(m2.find(p));
		adjust();
		return p;
	}
	int pm() {
		if (st.empty()) return -1;
		return *m1.rbegin();
	}
private:
	multiset<int> m1, m2;
	stack<int> st;
	void adjust()
	{
		if (m1.size() > m2.size()+1) {
			m2.insert(*m1.rbegin());
			m1.erase(m1.find(*m1.rbegin()));
		}
		else if (m1.size() < m2.size()) {
			m1.insert(*m2.begin());
			m2.erase(m2.begin());
		}
	}
};

int main()
{
	Stack st;
	int n;
	scanf("%d", &n);
	while (n--) {
		char cmd[15] = {0};
		scanf("%s", cmd);
		if (!strcmp(cmd, "Pop")) {
			int r = st.pop();
			if (r < 0) printf("Invalid\n");
			else printf("%d\n", r);
		}
		else if (!strcmp(cmd, "PeekMedian")) {
			int r = st.pm();
			if (r < 0) printf("Invalid\n");
			else printf("%d\n", r);
		}
		else {
			int v;
			scanf("%d", &v);
			st.push(v);
		}
	}
	return 0;
}