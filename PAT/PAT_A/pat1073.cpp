/*
Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[10001];

	scanf("%s", str);

	if (str[0] == '-') {
		printf("%c", str[0]);
	}

	char str2[10001];
	int index = 0;

	int i;
	for (i=1; i<strlen(str); i++) {

		if (str[i] == 'E') {
			str2[index] = '\0';
			break;
		}

		if (str[i] != '.') {
			str2[index++] = str[i];
		}
	}

	int exp;
	exp = atoi(str+i+1);

	if (exp >= 0) {
		printf("%c",str2[0]);
		int j;
		for (j=1; j<=exp; j++) {
			if ( j >= strlen(str2) )	printf("0");
			else printf("%c", str2[j]);
		}

		if ( j < strlen(str2)) {
			printf(".%s", str2+j);
		}
	}
	else {
		printf("0.");

		int j;
		for (j=-1; j>exp; j--) {
			printf("0");
		}
		printf("%s", str2);
	}

	return 0;
}