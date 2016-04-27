/*
People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

vector<string> d1={"", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> d2={"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string c1(string str) {
    int num = atoi(str.c_str());
    if (num == 0) return "tret";
    if (num <= 12) return d1[num];
    string result = d2[num/13];
    if (num%13) result += " " + d1[num%13];
    return result;
}

int c2(string str) {
    istringstream iss(str);
    string first, second;
    iss >> first >> second;
    if (first == "tret") return 0;
    if (find(d1.begin(), d1.end(), first) != d1.end()) return find(d1.begin(), d1.end(), first)-d1.begin();
    return 13*(find(d2.begin(), d2.end(), first)-d2.begin())+find(d1.begin(), d1.end(), second)-d1.begin();
}

int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--) {
        string line;
        getline(cin, line);
        if (line[0]>='0' && line[0]<= '9') cout << c1(line) << endl;
        else cout << c2(line) << endl;
    }
    return 0;
}