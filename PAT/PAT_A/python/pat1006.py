lt = []
for i in range(int(input())):
    lt.append(input().split())
a = min(lt, key=lambda x:x[1])[0]
b = max(lt, key=lambda x:x[2])[0]
print('%s %s'%(a, b))

