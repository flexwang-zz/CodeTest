def getrvalue(s, r):
 digits=[]
 while s > 0:
   digits.insert(0,s%r)
   s = int((s-(s%r))/r)
 curr = 1
 value = 0
 for i in range(len(digits)):
   value += digits[i]*curr
   curr *= r
#  print(value)
 return value


def isprime(r):
 if r < 2:
   return False
 if r == 2:
   return True
 for i in range(2, int(r/2)+2):
   if r%i == 0:
     return False
 return True


while True:
 s = input().split(' ')
 value = eval(s[0])
 if value < 0:
   break 
 if isprime(getrvalue(value, eval(s[1]))) and isprime(value):
   print('Yes')
 else:
   print('No')