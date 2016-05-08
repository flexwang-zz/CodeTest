import re
import glob
import os

def dfs(fn):
    lt = glob.glob(fn)
    for i in lt:
        if os.path.isdir(i):
            dfs(i+'\\*')
        else:
            try:
                pro(i)
            except:
                pass
def prol(s):
    pattern = re.compile('[ =]10[3-9]\D')
    r = s
    for i in pattern.finditer(s):
        span = i.span()
        r = r[:span[0]+3]+'^'+r[span[1]-2:]
    return r
def pro(fn):
    ext = os.path.splitext(fn)[1]
    if ext != '.cpp':
        return
    f = open(fn, 'r', encoding='utf-8')
    ls = f.readlines()
    lt = []
    for i in ls:
        lt.append(prol(i))
    g = open(fn, 'w', encoding='utf-8')
    for i in lt:
        g.write(i)
dfs('*')