/*
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 10^5) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/
#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <stdio.h>
#include <utility>

using namespace std;
struct Node{
    int key, next;
};

inline int abs(int x) {
    return x<0?-x:x;
}
  
int main()
{
    int n, head;
    cin >> head >> n;
    unordered_map<int, Node> um;
    unordered_set<int> visited;
    vector<pair<int,int>> removed;
    for (int i=0; i<n; i++) {
        int addr, key, next;
        cin >> addr >> key >> next;
        um[addr] = {key, next};
    }
    int p = head, pre;
    while (p >= 0) {
        int key = um[p].key;
        int next = um[p].next;
        if (visited.find(abs(key)) != visited.end()) {
            um[pre].next = next;
            removed.push_back(make_pair(p, key));
        }
        else {
            visited.insert(abs(key));
            pre = p;
        }
        p = next;
    }
    p = head;
    while (p >= 0) {
        printf("%05d %d ", p, um[p].key);
        if (um[p].next >= 0) printf("%05d\n", um[p].next);
        else printf("-1\n");
        p = um[p].next;
    }
    for (int i=0; i<removed.size(); i++) {
        printf("%05d %d ", removed[i].first, removed[i].second);
        if (i == removed.size()-1) printf("-1\n");
        else printf("%05d\n", removed[i+1].first);
    }
    return 0;
     
}
 