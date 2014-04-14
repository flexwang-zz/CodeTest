filehandle = open("F:\\GitHub\\CodeTest\\codejam\\2013R1B\\garbled_email_dictionary.txt")

dict = filehandle.readlines()

maxlen = 0
for x in dict:
	if len(x) > maxlen:
		maxlen = len(x)
print(maxlen)

T = eval(input())

for i in range(1, T+1):
	s = input()