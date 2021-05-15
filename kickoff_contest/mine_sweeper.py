import math

n, m = map(int, input().split())
deg = [[int(x) for x in input().split()] for i in range(n)]
b = [[0 for j in range(m)] for i in range(n)]
########

def rest_deg(i, j):
	ans = 0
	if (i > 0) and (b[i-1][j] == 1): ans+=1
	if (i < n-1) and (b[i+1][j] == 1): ans+=1
	if (j > 0) and (b[i][j-1] == 1): ans+=1
	if (j < m-1) and (b[i][j+1] == 1): ans+=1
	return deg[i][j] - ans

def get_result():
	if rest_deg(n-1, m-1) !=0:
		return
	for i in range(n):
		for j in range(m):
			print(b[i][j], end=' ')
		print()
	quit()

def calc(i, j):
	for x in range(2):
		b[i][j] = x
		stop = False

		if i > 0 and rest_deg(i-1, j) != 0:
			continue

		for k in range(1, min(n-i, j+1)):
			temp = rest_deg(i+k-1, j-k)
			if temp!=0 and temp!=1:
				stop = True
				break
			b[i+k][j-k] = temp

		if n-i < j+1 and rest_deg(n-1, j-n+i) != 0:
			stop = True

		if not stop:
			if i == n-1 and  j == m-1:
				get_result()
			elif i+j+1 < m:
				calc(i, j+1)
			else:
				calc(i+1, j)

		for k in range(1, min(n-i, j+1)):
			b[i+k][j-k] = 0

########
calc(0, 0)
