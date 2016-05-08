/*
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=10^4), the total number of users, K (<=5), the total number of problems, and M (<=1^05), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define max2(a,b) (a)>(b)?(a):(b)

struct node
{
	int id;
	vector<int> scores;
	bool isshow;
	int nperfect;
	int score;

	bool operator <(const node &another) const {
		if (another.score == score) {
			if (another.nperfect == nperfect) {
				return id < another.id;
			}

			return nperfect > another.nperfect;
		}

		return score > another.score;
	}
};

int main()
{
	int nuser, nproblem, nsubmit;

	scanf("%d %d %d", &nuser, &nproblem, &nsubmit);

	vector<node> nodes(nuser);

	for (int i=0; i<nuser; i++) {
		nodes[i].id = i+1;
		nodes[i].isshow = false;
		nodes[i].nperfect = 0;
		nodes[i].score = 0;
		nodes[i].scores = vector<int>(nproblem, -2);
	}

	vector<int> scores(nproblem);
	for (int i=0; i<nproblem; i++) {
		scanf("%d", &scores[i]);
	}

	for (int i=0; i<nsubmit; i++) {
		int id, problem, score;

		scanf("%d %d %d", &id, &problem, &score);

		if (nodes[id-1].scores[problem-1] < score) {
			nodes[id-1].scores[problem-1] = score;

			if (score >= 0 ) {
				nodes[id-1].isshow = true;
			}
		}
	}

	for (int i=0; i<nuser; i++) {
		for (int j=0; j<nproblem; j++) {
			nodes[i].score += max2(0, nodes[i].scores[j]);

			if (nodes[i].scores[j] == scores[j]) {
				nodes[i].nperfect ++;
			}
		}
	}

	sort(nodes.begin(), nodes.end());

	int rank = 1;

	for (int i=0; i<nodes.size(); i++) {
		if (!nodes[i].isshow)	break;

		if (i && nodes[i].score<nodes[i-1].score) {
			rank = i+1;
		}

		printf("%d ", rank);

		printf("%05d ", nodes[i].id);

		printf("%d", nodes[i].score);

		for (int j=0; j<nproblem; j++) {
			if (nodes[i].scores[j] > -2) {
				printf(" %d", max2(0, nodes[i].scores[j]));
			}
			else {
				printf(" -");
			}
		}
		printf("\n");
	}
	return 0;
}