/*
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/

#include <stdio.h>
#include <string.h>

#define size 100

char cap(char ch) {
	if (ch <= 'z' && ch >= 'a') {
		return ch - 32;
	}

	return ch;
}

bool contains(char *str, int len, char ch) {
	for (int i = 0; i < len; i++) {
		if (str[i] == ch)	
			return true;
	}

	return false;
}

int main()
{
	char str1[size], str2[size];
	char result[size];

	int len1, len2, len3;

	scanf("%s %s", str1, str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	len3 = 0;

	memset(result, '\0', size);

	int i2 = 0;
	for (int i1 = 0, i2=0; i1 < len1; i1++, i2++) {
		while (str1[i1] && str1[i1] != str2[i2]) {
			if (!contains(result, len3, cap(str1[i1]))) {
				result[len3++] = cap(str1[i1]);
			}
			i1++;
		}
	}

	printf("%s\n", result);

	return 0;
}