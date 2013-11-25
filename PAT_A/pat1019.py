def getdigits(n, b):
 digits = []
 while n > 0:
   r = n%b
   digits.insert(0,r)
   n = int((n-r)/b)
 return digits

def isreverse(digits):
 size  = len(digits)
 if size <= 1:
   return True
 for i in range(int(size/2)):
   if digits[i] != digits[size-i-1]:
     return False
 return True
s = input().split(' ')
n = eval(s[0])
b = eval(s[1])
digits = getdigits(n, b)
if isreverse(digits):
 print('Yes')
else:
 print('No')

size = len(digits)

if size <= 0:
 print('0')
else:
 for i in range(size):
   if i == size-1:
     print(digits[i], end='')
   else:
     print(digits[i], end=' ')