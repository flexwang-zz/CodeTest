/*
Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
*/

#include <stdio.h>

typedef long long LL;

LL gcd(LL a, LL b)
{
    return a ? gcd(b%a, a) : b;
}

LL lcm(LL a, LL b)
{
    return a*b / gcd(a, b);
}

int main()
{
    int n;

    scanf("%d", &n);

    LL a0 = 0;
    LL b0 = 1;
    LL i0 = 0;

    for (int ii = 0; ii < n; ii++) {
        LL a, b;
        scanf("%lld/%lld", &a, &b);
        
        i0 += a / b;

        a %= b;

        LL l = lcm(b, b0);

        a0 *= l / b0;
        a *= l / b;

        a0 += a;

        LL g = gcd(a0, l);

        b0 = l / g;
        a0 /= g;

        i0 += a0 / b0;

        a0 %= b0;
    }

    if (a0 < 0) {
        printf("-");
        a0 *= -1LL;
    }


    if (i0) {
        printf("%lld", i0);
    }

    if (i0 && a0) {
        printf(" ");
    }

    if (a0) {
        printf("%lld/%lld", a0, b0);
    }

    if (!i0 && !a0) {
        printf("0");
    }

    return 0;

}