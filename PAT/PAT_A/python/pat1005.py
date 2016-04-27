word=['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
sum = sum(map(int, input()))
lt = [word[int(i)] for i in str(sum)]
for i in range(len(lt)):
    print('%s%s'%(lt[i], '\n' if i==len(lt)-1 else ' '), end='')