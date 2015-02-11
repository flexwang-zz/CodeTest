/*
Description

Jessica's a very lovely girl wooed by lots of boys. Recently she has a problem. The final exam is coming, yet she has spent little time on it. If she wants to pass it, she has to master all ideas included in a very thick text book. The author of that text book, like other authors, is extremely fussy about the ideas, thus some ideas are covered more than once. Jessica think if she managed to read each idea at least once, she can pass the exam. She decides to read only one contiguous part of the book which contains all ideas covered by the entire book. And of course, the sub-book should be as thin as possible.

A very hard-working boy had manually indexed for her each page of Jessica's text-book with what idea each page is about and thus made a big progress for his courtship. Here you come in to save your skin: given the index, help Jessica decide which contiguous part she should read. For convenience, each idea has been coded with an ID, which is a non-negative integer.

Input

The first line of input is an integer P (1 ≤ P ≤ 1000000), which is the number of pages of Jessica's text-book. The second line contains P non-negative integers describing what idea each page is about. The first integer is what the first page is about, the second integer is what the second page is about, and so on. You may assume all integers that appear can fit well in the signed 32-bit integer type.

Output

Output one line: the number of pages of the shortest contiguous part of the book which contains all ideals covered in the book.

Sample Input

5
1 8 8 8 1
Sample Output

2
*/
#include <set>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int>     ps;
int             p;
set<int>        ideas;
int             nidea;
map<int, int>   maps;

int main()
{
    scanf("%d", &p);
    ps.resize(p);


    for (int i=0; i<p;i++) {
        scanf("%d", &ps[i]);
        ideas.insert(ps[i]);
    }

    nidea = ideas.size();

    int n = 0;
    int s = 0, t = 0;
    int ans = 0;
    for (;;) {
        for (;t<p && n < nidea;) {
            maps[ps[t]] ++;
            if (maps[ps[t++]] == 1) {
                
                n ++;

                if (n == nidea) {
                    if (ans == 0 || ans > t-s)
                        ans = t - s;
                    break;
                }
            }
        }



        while (n >= nidea && s < p) {
            
            maps[ps[s]]--;
            if (maps[ps[s]] == 0)
                n--;
            s ++;
            if (n == nidea) 
                if (ans == 0 || ans > t-s)
                    ans = t - s;
        }

        if (t == p)
            break;
        
    }

    printf("%d\n", ans);

    return 0;

}
