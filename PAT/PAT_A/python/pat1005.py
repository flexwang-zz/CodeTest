word=['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
sum = sum(map(int, input()))
lt = [word[int(i)] for i in str(sum)]
print(' '.join(lt))