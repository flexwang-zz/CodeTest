lt = list(map(int, input().split()))[1:]
cur = 0
def f(x):
    global cur
    if x-cur > 0:
        res = 5+(x-cur)*6
    else:
        res = 5+(cur-x)*4
    cur = x
    return res
res = sum(map(f, lt))
print(res)