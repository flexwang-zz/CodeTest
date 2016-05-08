/*
According to Wikipedia: "In mathematics and in particular in combinatorics, the Lehmer code is a particular way to encode each possible permutation of a sequence of n numbers." To be more specific, for a given permutation of items {A1, A2, ..., An}, Lehmer code is a sequence of numbers {L1, L2, ..., Ln} such that Li is the total number of items from Ai to An which are less than Ai. For example, given {24, 35, 12, 1, 56, 23}, the second Lehmer code L2 is 3 since from 35 to 23 there are three items, {12, 1, 23}, less than the second item, 35.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<= 10^5). Then N distinct numbers are given in the next line.

Output Specification:

For each test case, output in a line the corresponding Lehmer code. The numbers must be separated by exactly one space, and there must be no extra space at the beginning or the end of the line.

Sample Input:
6
24 35 12 1 56 23
Sample Output:
3 3 1 0 1 0
*/
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
    int v, n, pos;
};

void merge_sort(vector<Node>& v) {
    if (v.size() < 2) return;
    vector<Node> v1(v.begin(), v.begin()+v.size()/2);
    vector<Node> v2(v.begin()+v.size()/2, v.end());
    merge_sort(v1), merge_sort(v2);
    for (int i=0,j=0,k=0; k<v.size();) {
        if (j == v2.size()) v[k++] = v1[i++];
        else if (i==v1.size() || v1[i].v < v2[j].v) v[k++] = v2[j++];
        else {
            v1[i].n += v2.size()-j;
            v[k++] = v1[i++];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i=0; i<n; ++i) {
        cin >> nodes[i].v;
        nodes[i].n = 0;
        nodes[i].pos = i;
    }
    merge_sort(nodes);
    vector<int> res(n);
    for (auto &node: nodes)
        res[node.pos] = node.n;
    for (int i=0; i<n; ++i)
        printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}