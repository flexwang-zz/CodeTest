/*
 ﻿Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
 Input Specification:
 Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.
 Output Specification:
 For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
 registration_number final_rank location_number local_rank
 The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
 Sample Input:
 2
 5
 1234567890001 95
 1234567890005 100
 1234567890003 95
 1234567890002 77
 1234567890004 85
 4
 1234567890013 65
 1234567890011 25
 1234567890014 100
 1234567890012 85

 Sample Output:
 9
 1234567890005 1 1 1
 1234567890014 1 2 1
 1234567890001 3 1 2
 1234567890003 3 1 2
 1234567890004 5 1 4
 1234567890012 5 2 2
 1234567890002 7 1 5
 1234567890013 8 2 3
 1234567890011 9 2 4
 */

#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

class Testee {
public:
	char ID[14];
	int score;
	int localrank;
	int finalrank;
	int localnumber;

	bool operator<(const Testee t) const {
		if (score > t.score) {
			return true;
		}

		if (score == t.score) {
			return strcmp(ID, t.ID) < 0;
		}

		return false;
	}
};

int main() {
	int nlocation;
	vector<Testee> testees;

	scanf("%d", &nlocation);
	for (int ilocation = 1; ilocation <= nlocation; ilocation++) {
		vector<Testee> localtestees;
		int ntestee;
		scanf("%d", &ntestee);

		for (int i = 0; i < ntestee; i++) {
			Testee testee;
			scanf("%s %d", testee.ID, &testee.score);
			testee.localnumber = ilocation;
			localtestees.push_back(testee);
		}

		sort(localtestees.begin(), localtestees.end());

		int currank = 0;
		int prescore = -1;
		for (int i = 0; i < localtestees.size(); i++) {
			if (localtestees[i].score != prescore) {
				currank = i + 1;
			}
			localtestees[i].localrank = currank;
			prescore = localtestees[i].score;
		}
		testees.insert(testees.end(), localtestees.begin(), localtestees.end());
	}

	sort(testees.begin(), testees.end());
	int currank = 0;
	int prescore = -1;
	for (int i = 0; i < testees.size(); i++) {
		if (testees[i].score != prescore) {
			currank = i + 1;
		}
		testees[i].finalrank = currank;
		prescore = testees[i].score;
	}

	printf("%d\n", testees.size());

	for (int i = 0; i < testees.size(); i++) {
		printf("%s %d %d %d\n", testees[i].ID, testees[i].finalrank,
				testees[i].localnumber, testees[i].localrank);
	}

//  while(1);

	return 0;
}

