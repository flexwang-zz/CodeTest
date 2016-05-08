/*
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 10^5) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int to_int(const string &str, int d) {
    int res = 0;
    for (auto ch : str)
        res = res*d + ch-'0';
    return res;
}

string to_reversed_string(int n, int d) {
    string res;
    do {
        res += '0'+n%d;
        n /= d;
    }while(n);
    return res;
}

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i=2; i*i<=n; ++i)
        if (n%i == 0) return false;
    return true;
}

int main()
{
    int n, d;
    while (cin >> n >> d) {
        string str = to_reversed_string(n, d);
        int a = to_int(str, d);
        if (is_prime(a) && is_prime(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}