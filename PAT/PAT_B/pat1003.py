'''
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
'''
def accept(s):
    ca0 = 0
    ca1 = 0
    ca2 = 0
    cp = 0
    ct = 0
    for c in s:
        if c != 'P' and c != 'A' and c != 'T':
            return False
        if c == 'P':
            if cp > 0 or ct > 0:
                return False
            else:
                cp += 1
        if c == 'T': 
            if cp == 0 or ct > 0:
                return False
            else:
                ct += 1
        if c == 'A':
            if cp == 0:
                ca0 += 1
            elif ct == 0:
                ca1 += 1
            else:
                ca2 += 1
    if cp > 0 and ct > 0 and ca1 > 0 and (ca2 - ca0) == ca0 * (ca1 - 1):
        return True
    return False


n = int(input())
for i in range(n):
    s = input()
    print('YES' if accept(s) else 'NO')