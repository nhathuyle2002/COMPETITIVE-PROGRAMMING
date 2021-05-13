n = int(input())
a=[int(x) for x in input().split()]


def DP():
	while (True):
		stop = False
		for i in range(n):
			if a[i] % 2:
				stop = True
				break
		if stop: break
		for  i in range(n):
			a[i]//=2

	S = 0
	for i in range(n): 
		S += a[i]

	if S % 2: 
		return []
	S //= 2

	d = [False for x in range(S+1)]
	d[S] = True
	for i in range(n):
		for x in range(a[i], S+1):
			if d[x]: d[x - a[i]] = True

	if d[0] == False:
		return []
	else: 
		for i in range(n):
			if a[i] % 2:
				return [i+1]

ans = list(DP())
print(len(ans))
for x in ans: print(x, end=' ')

