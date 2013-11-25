'''
﻿Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).
Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:
12345

Sample Output:
one five
'''

digit={'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
word={0:'zero', 1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine'}
str = input();

sum = 0

for ch in str:
 sum += digit[ch]

str = ""

while sum >= 0:
 if sum < 10:
   str = word[sum%10] + str
 else:
   str = " " + word[sum%10] + str
 sum = int(sum/10)
 if sum == 0:
   break

print(str)
