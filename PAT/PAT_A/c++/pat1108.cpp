/*
The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A "legal" input is a real number in [-1000, 1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then N numbers are given in the next line, separated by one space.

Output Specification:

For each illegal input number, print in a line "ERROR: X is not a legal number" where X is the input. Then finally print in a line the result: "The average of K numbers is Y" where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case the average cannot be calculated, output "Undefined" instead of Y. In case K is only 1, output "The average of 1 number is Y" instead.

Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
Sample Input 2:
2
aaa -9999
Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_legal(string &str, double &t) 
{
    int cnt0 = 0, cnt1 = 0;
    for (int i=0; i<str.length(); ++i) {
        char ch = str[i];
        if (ch == '.') {
            if (cnt0 ++) return false;
        }
        else if (ch == '-') {
            if (i) return false;
        }
        else if (ch > '9' || ch < '0') 
            return false;
    }
    auto x = std::find(str.begin(), str.end(), '.');
    if (x != str.end() && (x-str.begin()+3) < str.length()) return false;
    t = atof(str.c_str());
    if (t < -1000 || t > 1000) return false;
    return true;
}

int main()
{
    int n, cnt;
    cin >> n;
    cnt = n;
    double sum = 0.0;
    for (int i=0; i<cnt; ++i) {
        string str;
        cin >> str;
        double x;
        if (!is_legal(str, x)) {
            --n;
            printf("ERROR: %s is not a legal number\n", str.c_str());
        }
        else 
            sum += x;
    }
    if (!n)
        printf("The average of 0 numbers is Undefined");
    else if (n == 1)
        printf("The average of 1 number is %.2f", sum);
    else
        printf("The average of %d numbers is %.2f", n, sum/n);
    return 0;
}