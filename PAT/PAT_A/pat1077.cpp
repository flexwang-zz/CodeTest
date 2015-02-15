/*
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[100][257];

	int n;

	scanf("%d", &n);

	getchar();

	for (int i=0; i<n; i++) {
		gets(str[i]);
	}

	int len = 0;
	while (1) {
		
		char ch = str[0][strlen(str[0])-len-1];

		bool flag = true;
		for (int i=1; i<n; i++) {
			if (len >= strlen(str[i])) {
				flag = false;
				break;
			}
			if (ch != str[i][strlen(str[i])-len-1]) {
				flag = false;
			}
		}

		if (flag) {
			len ++;
		}
		else {
			break;
		}
	}

	if (len) {
		printf("%s", &(str[0][strlen(str[0])-len]));
	}
	else {
		printf("nai");
	}

	return 0;

}