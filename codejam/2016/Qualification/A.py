def f(n):
    if n == 0:
        return 'INSOMNIA'
    tab = [False]*10
    cnt = 0
    sum = 0
    while tab != [True]*10:
        sum += n 
        cnt += 1
        s = str(sum)
        for ch in s:
            tab[int(ch)] = True
    return str(sum)

ncase = int(input())
for ic in range(ncase):
    print('Case #%d: %s'%((ic+1), f(int(input()))))
