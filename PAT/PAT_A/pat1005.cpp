/*
﻿Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).
Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:
12345

Sample Output:
one five
*/
#include <iostream>
#include <string>

using namespace std;

char tab[][10]={"zero", "one", "two", "three", "four", "five",
                "six", "seven", "eight", "nine"};

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    for (auto &ch:str)
        sum += ch-'0';
    string res = to_string(sum);
    for (int i=0; i<res.length(); ++i)
        printf("%s%c", tab[res[i]-'0'], i==res.length()-1?'\n':' ');
    return 0;
}