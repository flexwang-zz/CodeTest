import math

class Energy:
	def __init__(self, size, vi):
		self.size = size
		self.vi = vi
		
t = eval(input())

for i in range(1, t+1):
	e,r,n = map(int, input().split())
	v = map(int, input().split())
	
	energy = [Energy(e,0)]
	gain = 0

	for vi in v:
		size = 0
		for j in range(len(energy)-1, -1, -1):
			if energy[j].vi <= vi:
				gain -= energy[j].size*energy[j].vi
				size += energy[j].size
				energy.pop()
			else:
				break
		gain += size*vi
		energy.append(Energy(size, vi))
		
		R = r
		if r > e:
			energy = [Energy(e,0)]
		else:
			for j in range(len(energy)):
				if R > energy[j].size:
					R -= energy[j].size
				elif R == energy[j].size:
					j += 1
					break
				else:
					energy[j].size -= R
					break
			energy = energy[j:]
			energy.append(Energy(min(r,e), 0))
	print("Case #%d: %d" %(i, gain))