ncase = int(input())
for ic in range(ncase):
    k, c, s = map(int, input().split())
    print("Case #%d:"%(ic+1), end='')
    for i in range(k):
        print(' %d'%(1+i*k**(c-1)), end='')
    print()