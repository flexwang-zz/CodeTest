/*
 ﻿Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
 Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
 Input Specification:
 Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.
 Output Specification:
 For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
 Sample Input:
 1234567899

 Sample Output:
 Yes
 2469135798

 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string mul(const string& str, int n) 
{
    string res;
    int c = 0;
    for (int i=str.length()-1; i>=0; --i) {
        int v = c+(str[i]-'0')*n;
        res += '0'+v%10;
        c = v/10;
    }
    if (c) res.push_back(c+'0');
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a;
    cin >> a;
    string b = mul(a, 2), c = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << (a==b?"Yes":"No") << endl;
    cout << c << endl;
    return 0;
}