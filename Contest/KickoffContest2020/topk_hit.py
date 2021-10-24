import sys
from ctypes import c_long, c_longlong as ll

def treeAddValue(a, value):
    b = {()}
    b.clear()
    while (len(a) > 0):
        x = a.pop()
        b.add( (x[0] + value, x[1]) )
    #a = {(x[0] + value, x[1]) for x in a}
    return b

def take_first_second(x):
    return (x[1], x[0])

def treeLazy(i):
    lazy[i << 1] += lazy[i]
    lazy[i << 1|1] += lazy[i]

    t[i << 1] = treeAddValue(t[i << 1], lazy[i])
    t[i << 1|1] = treeAddValue(t[i << 1|1], lazy[i])
    lazy[i] = 0

def treeCreate(i, l, r):
    lazy[i] = 0
    if (l == r):
        t[i].clear()
        t[i].add((0, l))
        return
    
    mid = (l + r) // 2
    treeCreate(i << 1, l, mid)
    treeCreate(i << 1|1, mid +1, r)
    t[i] = t[i << 1] | t[i << 1|1]
    #t[i] = sorted(t[i], key = take_second, reverse = True)
    while (len(t[i]) > 5):
        t[i].remove(min(t[i]))

def up(i, l, r, u, v, x):
    if (v < l or u > r):
        return
    if (l >= u and r <= v):
        lazy[i] += x
        t[i] = treeAddValue(t[i], x)
        return 
    
    if (lazy[i] != 0):
        treeLazy(i)

    mid = (l+r) // 2
    up(i << 1, l, mid, u, v, x)
    up(i << 1|1, mid+1, r, u, v, x)
    t[i] = t[i << 1] | t[i << 1|1]
    #t[i] = sorted(t[i], key = take_second, reverse = True)
    while (len(t[i]) > 5):
        t[i].remove(min(t[i]))

maxn = 50000 * 4 +10

n, q = [int(x) for x in input().split()]
lazy = [(0) for i in range(maxn)]
t = [{()} for x in range(maxn)]

treeCreate(1, 1, n)
for i in range(q):
    arr = [int(x) for x in input().split()]
    if arr[0] == 1:
        up(1,1,n,arr[1],arr[2],arr[3])
    else:
        ans = []
        ans = t[1]
        ans = sorted(ans, reverse= True)
        for x in ans:
            print(x[1], end = " ")
            arr[1] -= 1
            if (arr[1] == 0):
                break
        print()
