/*
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef long long ll;

ll char2int(char ch) {
    if (ch <= '9' && ch >= '0')
        return ch - '0';
    return ch - 'a' + 10;
}

ll get_value(const string& str, ll rad) {
    ll res = 0ll;
    for (auto ch : str) 
        res = res*rad + char2int(ch);
    return res;
}

int main()
{
    string s1, s2;
    ll tag, r;
    cin >> s1 >> s2 >> tag >> r;
    if (tag == 2) swap(s1, s2);
    ll target = get_value(s1, r);
    ll lb = 1, ub;
    for (auto ch : s2)
        lb = max(lb, char2int(ch));
    for (ub=lb+1; get_value(s2, ub)<target; ub<<=1);
    while (lb+1 < ub) {
        ll m = (ub-lb)/2+lb;
        ll s = get_value(s2, m);
        if (s < target) lb = m;
        else ub = m;
    }

    if (get_value(s2, ub) == target)
        cout << ub << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}