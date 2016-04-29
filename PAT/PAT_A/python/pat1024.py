n, k = map(int, input().split())
is_pal = lambda x: str(x) == str(x)[::-1]
rev = lambda x: int(str(x)[::-1])
i = 0
while not is_pal(n) and i < k:
    n += rev(n)
    i += 1
print('%d\n%d'%(n, i));