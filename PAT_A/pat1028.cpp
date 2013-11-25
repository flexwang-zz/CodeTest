/*
 ﻿Excel can sort records according to any column. Now you are supposed to imitate this function.
 Input
 Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).
 Output
 For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.
 Sample Input 1
 3 1
 000007 James 85
 000010 Amy 90
 000001 Zoe 60

 Sample Output 1
 000001 Zoe 60
 000007 James 85
 000010 Amy 90

 Sample Input 2
 4 2
 000007 James 85
 000010 Amy 90
 000001 Zoe 60
 000002 James 98

 Sample Output 2
 000010 Amy 90
 000002 James 98
 000007 James 85
 000001 Zoe 60

 Sample Input 3
 4 3
 000007 James 85
 000010 Amy 90
 000001 Zoe 60
 000002 James 90

 Sample Output 3
 000001 Zoe 60
 000007 James 85
 000002 James 90
 000010 Amy 90


 */

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<iostream>
//#include<sstream>
//#include<algorithm>

using namespace std;

class Record {
public:
	char ID[7];
	char name[9];
	int score;
};

int lessthan1(const void *r1, const void *r2) {
	return strcmp((*(Record*) r1).ID, (*(Record*) r2).ID);
}

int lessthan2(const void *r1, const void *r2) {
	if (strcmp((*(Record*) r1).name, (*(Record*) r2).name) == 0) {
		return lessthan1(r1, r2);
	}

	return strcmp((*(Record*) r1).name, (*(Record*) r2).name);
}

int lessthan3(const void *r1, const void *r2) {
	if ((*(Record*) r1).score == (*(Record*) r2).score) {
		return lessthan1(r1, r2);
	}
	if ((*(Record*) r1).score < (*(Record*) r2).score) {
		return -1;
	}
	return 1;
}

int main() {
	int n, c;

	scanf("%d %d", &n, &c);
	Record records[100000];

	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", records[i].ID, records[i].name, &records[i].score);
	}
	if (c == 1) {
		qsort((void*) records, n, sizeof(Record), lessthan1);
	} else if (c == 2) {
		qsort((void*) records, n, sizeof(Record), lessthan2);
	} else {
		qsort((void*) records, n, sizeof(Record), lessthan3);
	}
	for (int i = 0; i < n; i++) {
		cout << records[i].ID << " " << records[i].name << " "
				<< records[i].score << endl;
	}

	return 0;
}

