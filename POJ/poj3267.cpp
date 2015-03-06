/*
Description

Few know that the cows have their own dictionary with W (1 ¡Ü W ¡Ü 600) words, each containing no more 25 of the characters 'a'..'z'. Their cowmunication system, based on mooing, is not very accurate; sometimes they hear words that do not make any sense. For instance, Bessie once received a message that said "browndcodw". As it turns out, the intended message was "browncow" and the two letter "d"s were noise from other parts of the barnyard.

The cows want you to help them decipher a received message (also containing only characters in the range 'a'..'z') of length L (2 ¡Ü L ¡Ü 300) characters that is a bit garbled. In particular, they know that the message has some extra letters, and they want you to determine the smallest number of letters that must be removed to make the message a sequence of words from the dictionary.

Input

Line 1: Two space-separated integers, respectively: W and L 
Line 2: L characters (followed by a newline, of course): the received message 
Lines 3..W+2: The cows' dictionary, one word per line
Output

Line 1: a single integer that is the smallest number of characters that need to be removed to make the message a sequence of dictionary words.
Sample Input

6 10
browndcodw
cow
milk
white
black
brown
farmer
Sample Output

2
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int   max_w = 601;
const int   max_l = 302;
char        str[max_l];
int         w, l;
char        dict[max_w][26];
int         len[max_w];
int         dp[max_l];


int main()
{
    scanf("%d%d", &w, &l);
    scanf("%s", str);
    for (int i=0; i<w; i++) {
        scanf("%s", dict[i]);
        len[i] = strlen(dict[i]);
    }

    dp[0] = 0;
    for (int i=1; i<=l; i++) {
        dp[i] = dp[i-1] + 1;
        for (int iw=0; iw<w; iw++) {
            int t = len[iw]-1;
            int s = i-1;
            while (s>=0) {
                if (dict[iw][t] == str[s])
                    t--;
                if (t < 0)
                    break;
                s--;
            }
            if (t < 0)
                dp[i] = min(dp[i], dp[s]+i-s-len[iw]);
        }
    }
    printf("%d\n", dp[l]);
    return 0;
}