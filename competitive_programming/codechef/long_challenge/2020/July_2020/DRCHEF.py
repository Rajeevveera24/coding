# cook your dish here

def cnt2(a, b):
    cnt = 1
    while 2*a < b:
        cnt += 1
        a = a*2
    return cnt
    
for _ in range(int(input())):
    
    n,x = map(int, input().split())
    
    a = sorted(list(map(int, input().split())))
    
    if x >= a[n-1]:
        print(n)
        continue
    
    c = list(x for x in a)
    
    i = n-2
    
    c[n-1] = 1
    acc = 1
    
    while i >= 0:
        # print(a[i], a[i+1])
        # print(cnt2(a[i], a[i+1]))
        c[i] = acc + cnt2(a[i], a[i+1])
        acc = c[i]
        i -= 1
    
    d = list()
    
    for num in a:
        if num <= x:
            d.append(0)
        else:
            d.append(int(cnt2(x, num)))

    # print(c)
    # print(d)
    
    mindays = 10**9
    
    for i in range(n):
        # print(c[i] + d[i] + i)
        if (c[i] + d[i] + i) < mindays:
            mindays = (c[i] + d[i] + i)
    
    print(mindays)
    
    
    