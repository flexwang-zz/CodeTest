n, k = map(int, input().split())
is_pal = lambda x: str(x) == str(x)[::-1]
rev = lambda x: int(str(x)[::-1])
if is_pal(n):
    print('%d\n%d'%(n, 0))
    exit()
for i in range(1, k+1):
    n += rev(n)
    if is_pal(n):
        k = i
        break
print('%d\n%d'%(n, k));