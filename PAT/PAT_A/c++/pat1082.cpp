/*
Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. Output "Fu" first if it is negative. For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu". Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".

Input Specification:

Each input file contains one test case, which gives an integer with no more than 9 digits.

Output Specification:

For each test case, print in a line the Chinese way of reading the number. The characters are separated by a space and there must be no extra space at the end of the line.

Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
*/

#include <stdio.h>
#include <string.h>

char unit[][10] = {"Yi", "Qian", "Bai", "Shi", "Wan", "Qian", "Bai", "Shi", "Yi"};
char digit[][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi" };

int main()
{
    char *str = new char[11];
    memset(str, '\0', 11);
    scanf("%s", str);

    
    int len = strlen(str);
    if (str[0] == '-') {
        printf("Fu ");
        len--;
        str++;
    }
    if (!strcmp(str, "10")) {
        printf("shi");
        return 0;
    }

    bool has_zero_before = false;
    bool just_has_yi_before = true;
    for (int i = 0; i < len; i++) {
        int d = str[i] - '0';
        int u = 9 - len + i;
        if (d) {
            if (u)
                just_has_yi_before = false;
            if (has_zero_before)
                printf(" ling");
            has_zero_before = false;
            if (i) 
                printf(" ");

            printf("%s", digit[d]);

            if (u != 8)
                printf(" %s", unit[u]);
        }
        else {
            if (u == 4 && !just_has_yi_before)
                printf(" Wan");
            has_zero_before = true;
        }
    }

    if (!strcmp(str, "0"))
        printf("ling");
    return 0;
}