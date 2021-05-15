import math

base = 27
n , m, Q = map(int, input().split())

a = [input() for i in range(n)]

b = []
ans = []

for i in range(n):
	for j in range(m):
		H = 0
		for k in range(j, min(m, j+10)):
			H = H*base + ord(a[i][k]) - ord('a') + 1
			b.append(H)

for j in range(m):
	for i in range(n):
		H=0
		for k in range(i, min(n, i+10)):
			H = H*base + ord(a[k][j]) - ord('a') + 1
			b.append(H)

b.sort()

def binary_search(left, right, x):
	while left < right:
		mid = (left+right) // 2
		if b[mid] == x:
			return True
		elif b[mid] < x:
			left = mid+1
		else:
			right = mid
	return False

while Q > 0:
	Q -= 1
	t = input()
	H = 0
	for x in t:
		H = H*base + ord(x) - ord('a') + 1
	if binary_search(0, len(b), H):
		ans.append(1)
	else:
		ans.append(0)

for x in ans: print(x, end='')
