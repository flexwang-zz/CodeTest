def ink(n, r):
	return int(2*n*n+(2*r-1)*n)
	
def b_search(start, end, r, t):
	if (end-start) <= 1:
		return start
	mid = int((end+start)/2)
	result = ink(mid,r)
	
	if result == t:
		return mid
	elif result > t:
		return b_search(start, mid, r, t)
	else:
		return b_search(mid, end, r, t)

T = eval(input())

for i in range(1, T+1):
	r, t = map(int, input().split())
	n = 1
	while ink(n,r) <= t:
		n *= 2
	print("Case #%d: %d" %(i,b_search(n/2, n, r, t)))
	