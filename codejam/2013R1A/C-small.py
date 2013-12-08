def solve1(clue):
	dict = {2*5*5:"255", 3*5*5:"355", 4*5*5:"455", 5*5*5:"555",
		2*4*4:"244", 3*4*4:"344", 4*4*4:"444", 5*4*4:"445",
		2*3*3:"233", 3*3*3:"333", 4*3*3:"334", 5*3*3:"335",
		2*3*4:"234", 2*3*5:"235", 3*4*5:"345"
		}
	if clue in dict:
		print(dict[clue])
		return True
	return False

def hasn(a, n):
	for x in a:
		if x%n == 0:
			return True
	return False
def hasn2(a, n):
	for x in a:
		if x==n:
			return True
	return False
input()
input()
print("Case #1:")
for i in range(1, 101):
	a = map(int, input().split())
	
	clue1 = max(a)
	if not solve1(clue1):
		if hasn(a, 25):
			solved = False
			for x in [4,2,3]:
				if hasn(a, x):
					solved = True
					print("%d55" %x)
					break
			if not solved:
				print("255")
		elif hasn(a, 9):
			solved = False
			for x in [4,2,5]:
				if hasn(a, x):
					solved = True
					print("%d33" %x)
					break
			if not solved:
				print("233")
		elif hasn(a, 16):
			solved = False
			for x in [3,5]:
				if hasn(a, x):
					solved = True
					print("%d44" %x)
					break
			if not solved:
				print("244")
		else:
			print("234")