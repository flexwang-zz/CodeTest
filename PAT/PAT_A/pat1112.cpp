/*
On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.

Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.

Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string "thiiis iiisss a teeeeeest" we know that the keys "i" and "e" might be stucked, but "s" is not even though it appears repeatedly sometimes. The original string could be "this isss a teest".

Input Specification:

Each input file contains one test case. For each case, the 1st line gives a positive integer k ( 1<k<=100 ) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and "_". It is guaranteed that the string is non-empty.

Output Specification:

For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.

Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest
Sample Output:
ei
case1__this_isss_a_teest
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int k;
string str;
vector<char> res;
unordered_set<char> um;



int main()
{
    cin >> k;
    cin >> str;
    for (int i=0; i<str.length(); ++i) {
        if (um.find(str[i]) != um.end()) continue;
        bool found = true;
        for (int j=1; j<k; ++j) 
            if (j+i >= str.length()) found = false;
            else if (str[j+i] != str[i]) found = false;
        if (found) {
            for (int j=0; j<str.length();)
                if (str[j] == str[i]) {
                    for (int m=1; m<k; ++m)
                        if (m+j >= str.length()) found = false;
                        else if (str[m+j] != str[i]) found = false;
                    if (!found) break;
                    else j += k;
                }
                else ++j;
            if (found) {
                string r;
                for (int j=0; j<str.length(); str[j]==str[i]?j+=k:++j) 
                    r += str[j];
                str = r;
                um.insert(str[i]);
                res.push_back(str[i]);
            }
        }
    }
    for (auto x:res)
        cout << x;
    cout << endl;
    cout << str;
    return 0;

}