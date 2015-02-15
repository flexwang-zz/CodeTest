def getrank(id, dict, course):
 rank = 1
 score = dict[id][course]
 for d,x in dict.items():
   if d != id and x[course] > score:
     rank += 1
 return rank

s = input().split(' ')
nstudents = eval(s[0])
nquery = eval(s[1])

dict = {}
for i in range(nstudents):
 s = input().split(' ')
 
 c = eval(s[1])
 m = eval(s[2])
 e = eval(s[3])
 a = (c+m+e)/3
 dict[s[0]] = (a, c, m, e)
 
for i in range(nquery):
 id = input()
 if not id in dict:
   print('N/A')
 else:
   course = ['A','C','M','E']
   bestrank = 200001
   bestcourse = -1
   for j in range(4):
     rank = getrank(id, dict, j)
     if rank < bestrank:
       bestrank = rank
       bestcourse = j
   print(bestrank, end=' ')
   print(course[bestcourse])