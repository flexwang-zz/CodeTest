def gen_primes(n):
    lt = [2]
    cur = 3
    while len(lt) < n:
        flag = True
        for i in lt:
            if cur % i == 0:
                flag = False
                break
            if i*i > cur:
                break
        if flag:
            lt.append(cur)
        cur += 1
    return lt
def is_prime(n, primes):
    for p in primes:
        if n%p == 0:
            return p
        if p*p > n:
            return -1
    return -1
def to_int(s, b):
    res = 0
    for c in s:
        res = res*b + int(c)
    return res
def test(s, primes):
    div = [-1]*9
    for b in range(2, 11):
        n = to_int(s, b)
        d = is_prime(n, primes)
        if d < 0:
            return None
        else:
            div[b-2] = d
    return div

N, J = map(int, input().split())
primes = gen_primes(10000)
print('Case #1:')
cnt = 0
for i in range(1<<(N-2)):
    form = '{0:0%db}'%(N-2)
    s = '1'+form.format(i)+'1'
    div = test(s, primes)
    if div is not None:
        print(s, end='')
        for d in div:
            print(' %d'%d, end='')
        print()
        cnt += 1
        if cnt == J:
            break
    
