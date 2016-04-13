def f(s):
    cnt = 0
    for c in reversed(s):
        if c=='+' and cnt%2!=0 or c=='-' and cnt%2==0:
            cnt += 1
    return cnt
ncase = int(input())
for ic in range(ncase):
    print('Case #%d: %d'%(ic+1, f(input())))