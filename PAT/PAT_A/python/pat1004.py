n, m = map(int, input().split())
g = [[] for _ in range(n+1)]
for i in range(m):
    lt = list(map(int, input().split()))
    g[lt[0]] = lt[2:]
level = [1]
res = []
while level:
    next = []
    cnt = 0
    for i in level:
        for j in g[i]:
            next.append(j)
        if not g[i]:
            cnt += 1
    res.append(cnt)
    level = next
for i in range(len(res)):
    print('%d%s'%(res[i], '\n' if i==len(res)-1 else ' '), end='')