/*
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

Ki: hi[1] hi[2] ... hi[Ki]

where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int sum;
    int father;
};



const int max_n = 1002;
Node nodes[max_n];
vector<int> h[max_n];
int n;

int find(int i) {
    if (nodes[i].father == i) return i;
    return nodes[i].father = find(nodes[i].father);
}

void unite(int i, int j) {
    int x = find(i);
    int y = find(j);
    if (x != y) {
        nodes[x].father = y;
        nodes[y].sum += nodes[x].sum;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        nodes[i].sum = 1;
        nodes[i].father = i;
        int cnt;
        scanf("%d:", &cnt);
        while (cnt--) {
            int x;
            scanf("%d", &x);
            h[x-1].push_back(i);
        }
    }
    for (int i=0; i<1000; ++i) {
        for (int j=0; j+1<h[i].size(); ++j)
            unite(h[i][j], h[i][j+1]);
    }
    vector<int> res;
    for (int i=0; i<n; ++i)
        if (nodes[i].father == i) res.push_back(nodes[i].sum);
    sort(res.begin(), res.end(), greater<int>());
    printf("%d\n", res.size());
    for (int i=0; i<res.size(); ++i)
        printf("%d%c", res[i], i==res.size()-1?'\n':' ');
    return 0;
}