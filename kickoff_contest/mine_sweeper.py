import math

n, m = map(int, input().split())
deg = [[int(x) for x in input().split()] for i in range(n)]
b = [[-1 for j in range(m)] for i in range(n)]
########

def set_neighbor(i, j, x):
	if i > 0: b[i-1][j] = x
	if i < n-1: b[i+1][j] = x
	if j > 0: b[i][j-1] = x
	if j < m-1: b[i][j+1] = x

def rest_deg(i, j):
	ans = 0
	if (i > 0) and (b[i-1][j] == 1): ans+=1
	if (i < n-1) and (b[i+1][j] == 1): ans+=1
	if (j > 0) and (b[i][j-1] == 1): ans+=1
	if (j < m-1) and (b[i][j+1] == 1): ans+=1
	return deg[i][j] - ans

def calc(i, j):
	if j == 0 and i > 1:
		for y in range(m):
			if rest_deg(i-2, y) != 0:
				return

	if i >= n:
		stop = True
		for x in range(n):
			for y in range(m):
				if rest_deg(x, y) != 0: 
					stop = False
					break
			if not stop:
				break
		if stop:
			for x in range(n):
				for y in range(m):
					print(b[x][y], end=' ')
				print()
			quit()
		return

	x, y = i + (j+1)//m, (j+1) % m

	if b[i][j] != -1:
		calc(x, y)
		return
	if (i == 0) or (rest_deg(i-1, j) == 0):
		b[i][j] = 0
		calc(x, y)
	if (i == 0) or (rest_deg(i-1, j) == 1):
		b[i][j] = 1
		calc(x, y)
	b[i][j] = -1

########

for i in range(n):
	for j in range(m):
		if deg[i][j] == 0:
			set_neighbor(i, j, 0)
		elif deg[i][j] == 4:
			set_neighbor(i, j, 1)

calc(0, 0)
