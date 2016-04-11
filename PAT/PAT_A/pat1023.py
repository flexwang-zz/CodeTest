a = int(input())
if sorted(str(a)) == sorted(str(a*2)):
    print("Yes")
else:
    print("No")
print(a*2)