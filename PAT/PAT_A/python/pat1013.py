def find(v, root):
    if root[v] != v:
        root[v] = find(root[v], root)
    return root[v]
def unit(v, t, root):
    rv = find(v, root)
    rt = find(t, root)
    if rv != rt:
        root[rv] = rt
n, m, k = map(int, input().split())
es = [tuple(map(int, input().split())) for _ in range(m)]
for t in map(int, input().split()):
    root = list(range(n))
    for e in es:
        if e[0] != t and e[1] != t:
            unit(e[0]-1, e[1]-1, root)
    res = sum(map(lambda x,y:x == y, range(n), root))
    print(res-2)