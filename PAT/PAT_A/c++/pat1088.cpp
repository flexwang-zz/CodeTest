/*
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/

#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}

ll lcm(ll a, ll b) {
    return a*b / gcd(a,b);
}

void print(
    ll a,
    ll b)
{
    if (b == 0) {
        printf("Inf");
        return;
    }
    if (a == 0) {
        printf("0");
        return;
    }

    ll g = gcd(a, b);
    a /= g;
    b /= g;
    bool negative = a*b < 0ll;

    if (b < 0ll) b = -b;
    if (a < 0ll) a = -a;

    if (negative)
        printf("(-");

    ll i = a / b;
    if (i > 0)
        printf("%lld", i);
    a %= b;

    if (a != 0) {
        if (i > 0)  printf(" ");
        printf("%lld/%lld", a, b);
    }

    if (negative)
        printf(")");
}

void add(
    ll a1,
    ll b1,
    ll a2,
    ll b2,
    ll &a,
    ll &b)
{
    b = lcm(b1, b2);
    a = b/b1*a1 + b/b2*a2;
}

void sub(
    ll a1,
    ll b1,
    ll a2,
    ll b2,
    ll &a,
    ll &b)
{
    add(a1, b1, -a2, b2, a, b);
}

void mul(
    ll a1,
    ll b1,
    ll a2,
    ll b2,
    ll &a,
    ll &b)
{
    a = a1*a2;
    b = b1*b2;
}

void div(
    ll a1,
    ll b1,
    ll a2,
    ll b2,
    ll &a,
    ll &b)
{
    mul(a1, b1, b2, a2, a, b);
}

int main()
{
    ll a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

    ll a, b;
    print(a1, b1); printf(" + "); print(a2, b2); printf(" = ");
    add(a1, b1, a2, b2, a, b);
    print(a, b);
    printf("\n");

    print(a1, b1); printf(" - "); print(a2, b2); printf(" = ");
    sub(a1, b1, a2, b2, a, b);
    print(a, b);
    printf("\n");

    print(a1, b1); printf(" * "); print(a2, b2); printf(" = ");
    mul(a1, b1, a2, b2, a, b);
    print(a, b);
    printf("\n");

    print(a1, b1); printf(" / "); print(a2, b2); printf(" = ");
    div(a1, b1, a2, b2, a, b);
    print(a, b);
    printf("\n");

    return 0;
}