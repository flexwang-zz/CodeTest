
#include<stdio.h>

#define Max(a,b,c) (a>b&&a>c?a:(b>c?b:c))

int strlen(char *);

int main() {
	int repeat;
	char index[] = "0123456789";

	scanf("%d", &repeat);

	for (int i = 0; i < repeat; i++) {
		char a[64], b[64], c[64], d[64];

		scanf("%s %s %s", a, b, c);
		//  printf("%s %s %s\n", a, b, c);

		unsigned int A1, B1, C1, A2, B2, C2;
		int sa, sb, sc, sd;

		sa = (a[0] == '-') ? -1 : 1;
		sb = (b[0] == '-') ? -1 : 1;
		sc = (c[0] == '-') ? -1 : 1;

		int lena = strlen(a);
		int lenb = strlen(b);
		int lenc = strlen(c);

		if (sa < 0) {
			for (int j = 0; j < lena; j++) {
				a[j] = a[j + 1];
			}
		}
		if (sb < 0) {
			for (int j = 0; j < lenb; j++) {
				b[j] = b[j + 1];
			}
		}

		if (sc < 0) {
			for (int j = 0; j < lenc; j++) {
				c[j] = c[j + 1];
			}
		}
		int len = Max(lena, lenb, lenc);

		bool flag = false;
		for (int j = 0; j < len; j++) {
			int ma = 0, mb = 0, mc = 0;
			if (j + lena >= len) {
				if (a[j + lena - len] != '-') {
					//printf("%c", a[len-j-lena]);
					ma = a[j + lena - len] - '0';
					ma *= sa;
				}

			}
			if (j + lenb >= len) {
				if (b[-len + j + lenb] != '-') {
					mb = b[-len + j + lenb] - '0';
					mb *= sb;
				}

			}
			if (j + lenc >= len) {
				if (c[-len + j + lenc] != '-') {
					mc = c[-len + j + lenc] - '0';
					mc *= sc;
				}
			}

			//printf("%d %d %d\n", ma, mb, mc);
			if (ma + mb > mc) {
				flag = true;
				break;
			} else if (ma + mb < mc) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			printf("Case #%d: false\n", i + 1);
		} else {
			printf("Case #%d: true\n", i + 1);
		}

	}

	return 0;
}

int strlen(char *str) {
	int len = 0;
	while (str[len] != ' ' && str[len] != '\0')
		len++;

	if (str[0] == '-')
		len--;
	return len;
}

