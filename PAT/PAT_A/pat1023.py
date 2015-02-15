def getpermutation(value):
 dict = []
 for i in range(10):
   dict.append(0)
 s = str(value)
 for i in range(len(s)):
   dict[eval(s[i])] += 1
 return dict

s = eval(input())

if getpermutation(s) == getpermutation(2*s):
 print('Yes')
else:
 print('No')
print(2*s)
