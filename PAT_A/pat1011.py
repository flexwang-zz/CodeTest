odd = 1
t = ''
for i in range(3):
        s = input().split(' ')
        m = max(eval(s[0]), eval(s[1]), eval(s[2]))
        if m == eval(s[0]):
                t += 'W '
        elif m == eval(s[1]):
                t += 'T '
        else:
                t += 'L '
        odd *= m
odd = (odd*0.65-1)*2
print(t, end='')
print('%.2f'%(odd))