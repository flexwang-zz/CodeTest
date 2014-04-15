T = eval(input())

for i in range(1, T+1):
	a,n  = map(int, input().split())
	l = [int(x) for x in input().split()]
	l.sort()
	totalop = 0
	minop = n
	
	if a <= 1:
		print("Case #%d: %d" %(i, n))
	else:
		for j in range(n):
			while a <= l[j]:
				a = 2*a - 1
				totalop += 1
			if totalop + (n-j-1) < minop:
				minop = totalop + (n-j-1)
			elif totalop >= minop:
				break
			a += l[j]
		print("Case #%d: %d" %(i, minop))