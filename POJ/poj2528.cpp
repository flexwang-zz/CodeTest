/*
Description

The citizens of Bytetown, AB, could not stand that the candidates in the mayoral election campaign have been placing their electoral posters at all places at their whim. The city council has finally decided to build an electoral wall for placing the posters and introduce the following rules: 
Every candidate can place exactly one poster on the wall. 
All posters are of the same height equal to the height of the wall; the width of a poster can be any integer number of bytes (byte is the unit of length in Bytetown). 
The wall is divided into segments and the width of each segment is one byte. 
Each poster must completely cover a contiguous number of wall segments.

They have built a wall 10000000 bytes long (such that there is enough place for all candidates). When the electoral campaign was restarted, the candidates were placing their posters on the wall and their posters differed widely in width. Moreover, the candidates started placing their posters on wall segments already occupied by other posters. Everyone in Bytetown was curious whose posters will be visible (entirely or in part) on the last day before elections. 
Your task is to find the number of visible posters when all the posters are placed given the information about posters' size, their place and order of placement on the electoral wall. 
Input

The first line of input contains a number c giving the number of cases that follow. The first line of data for a single case contains number 1 <= n <= 10000. The subsequent n lines describe the posters in the order in which they were placed. The i-th line among the n lines contains two integer numbers li and ri which are the number of the wall segment occupied by the left end and the right end of the i-th poster, respectively. We know that for each 1 <= i <= n, 1 <= li <= ri <= 10000000. After the i-th poster is placed, it entirely covers all wall segments numbered li, li+1 ,... , ri.
Output

For each input data set print the number of visible posters after all the posters are placed. 

The picture below illustrates the case of the sample input. 

Sample Input

1
5
1 4
2 6
8 10
3 4
7 10
Sample Output

4
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;
typedef pair<int,int> P;
const int   max_n = (10000*2+2)*4;
int         dat[max_n];
bool        flag[max_n];
vector<int> v;
vector<P>   ps;
set<int>    posters;
int         dat_size;
int         n;

void compress()
{
    vector<int> tab = v;
    sort(tab.begin(), tab.end());
    tab.erase(unique(tab.begin(), tab.end()), tab.end());
    dat_size = tab.size();
    for (int i=0; i<v.size()/2; i++) {
        ps[i].first = find(tab.begin(), tab.end(), v[i*2]) - tab.begin();
        ps[i].second = find(tab.begin(), tab.end(), v[i*2+1]) - tab.begin();
    }
}
void init_segment_tree()
{
    fill(dat, dat+max_n, -1);
    fill(flag, flag+max_n, true);
}
void update(int a, int b, int value, int k, int x, int y)
{
    if (a<=x && y<=b) {
        dat[k] = value;
        flag[k] = true;
    }
    else if (b<=x || y<=a)
        return;
    else {
        if (dat[k] >=0 && flag[k]) {
            update(x, y, dat[k], k*2+1, x, (x+y)/2);
            update(x, y, dat[k], k*2+2, (x+y)/2, y);
        }
        flag[k] = false;
        update(a, b, value, k*2+1, x, (x+y)/2);
        update(a, b, value, k*2+2, (x+y)/2, y);
    }
}
void calc(int k, int x, int y)
{
    if (flag[k]) {
        if (dat[k] >= 0)
            posters.insert(dat[k]);
    }
    else {
        calc(k*2+1, x, (x+y)/2);
        calc(k*2+2, (x+y)/2, y);
    }
}

void solve()
{
    scanf("%d", &n);
    v.resize(n*2);
    ps.resize(n);
    posters.clear();
    for (int i=0; i<n; i++) 
        scanf("%d%d", &v[i*2], &v[i*2+1]);
    compress();
    init_segment_tree();
    for (int i=0; i<n; i++)
        update(ps[i].first, ps[i].second+1, i, 0, 0, dat_size);
    calc(0, 0, dat_size);
    printf("%d\n", posters.size());
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--)
        solve();
    return 0;
}