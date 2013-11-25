radix = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'a':10,'b':11,'c':12,'d':13,'e':14,'f':15,'g':16,'h':17,'i':18,'j':19,'k':20,'l':21,'m':22,'n':23,'o':24,'p':25,'q':26,'r':27,'s':28,'t':29,'u':30,'v':31,'w':32,'x':33,'y':34,'z':35}

def getvalue(digits, r):
 curr = 1
 value = 0
 for i in range(len(digits)):
   value += radix[digits[len(digits)-i-1]]*curr
   curr *= r
 return value

s = input().split(' ')
r = eval(s[3])
if s[2] == '1':
 fr = s[0]
 to = s[1]
else:
 fr = s[1]
 to = s[0]
value = getvalue(fr, r)
minr = 1
for i in range(len(to)):
 if radix[to[i]] > minr:
   minr = radix[to[i]]
minr += 1


found = False
if getvalue(to, minr) > value:
 print('Impossible', end='')
else:
 maxr = minr
 while(getvalue(to, maxr) < value):
   maxr *= 2
 maxr += 1
 while(True):
   midr = int((minr + maxr)/2)
   value2 = getvalue(to, midr)
   if value2 < value:
     minr = midr
   elif value2 > value:
     maxr = midr
   else:
     print(midr,end='')
     found = True
     break
   if (maxr-minr) <= 1:
     if getvalue(to, maxr) == value:
       print(maxr,end='')
       found = True
     elif getvalue(to, minr) == value:
       print(minr,end='')
       found = True
     break
 if not found:
   print('Impossible', end='')