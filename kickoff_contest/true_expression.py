import math

n, S = map(int, input().split())
Sum = n*(n+1)//2

if S > Sum:
	print("NO_SOLUTION")
	quit()

d = [[False for x in range(Sum+1)] for i in range(n+1)]

d[0][Sum] = True

for i in range(1, n+1):
	for x in range(Sum+1):
		if d[i-1][x] or (x+i*2 <= Sum and d[i-1][x+i*2]):
			d[i][x] = True

if not d[n][S]:
	print("NO_SOLUTION")
else:
	ans = ""
	x = S
	i = n
	while i > 0:
		if d[i-1][x]: 
			ans = '+' + ans
		else:
			x = x + i*2
			ans = '-' + ans
		i -= 1
	print(ans)
