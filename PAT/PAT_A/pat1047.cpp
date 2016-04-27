/*
 ﻿Zhejiang University has 40000 students and provides 2500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=40000), the total number of students, and K (<=2500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (<=20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.
 Output Specification:
 For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.
 Sample Input:
 10 5
 ZOE1 2 4 5
 ANN0 3 5 2 1
 BOB5 5 3 4 2 1 5
 JOE4 1 2
 JAY9 4 1 2 5 4
 FRA8 3 4 2 5
 DON2 2 4 5
 AMY7 1 5
 KAT3 3 5 4 2
 LOR6 4 2 4 1 5

 Sample Output:
 1 4
 ANN0
 BOB5
 JAY9
 LOR6
 2 7
 ANN0
 BOB5
 FRA8
 JAY9
 JOE4
 KAT3
 LOR6
 3 1
 BOB5
 4 7
 BOB5
 DON2
 FRA8
 JAY9
 KAT3
 LOR6
 ZOE1
 5 9
 AMY7
 ANN0
 BOB5
 DON2
 FRA8
 JAY9
 KAT3
 LOR6
 ZOE1
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<pair<string,int>> pos(n);
    vector<vector<int>> tab(n);
    for (int i=0; i<n; ++i) {
        cin >> pos[i].first;
        pos[i].second = i;
        int cnt;
        scanf("%d", &cnt);
        for (int j=0; j<cnt; ++j) {
            int course;
            scanf("%d", &course);
            tab[i].push_back(course-1);
        }
    }
    sort(pos.begin(), pos.end());
    vector<vector<string>> res(k);
    for (auto &p : pos)
        for (auto &q : tab[p.second])
            res[q].push_back(p.first);
    for (int i=0; i<k; ++i) {
        printf("%d %d\n", i+1, res[i].size());
        for (auto &s : res[i]) 
            printf("%s\n", s.c_str());
    }
    return 0;
}
