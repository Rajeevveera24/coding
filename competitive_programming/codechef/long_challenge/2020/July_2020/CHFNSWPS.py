# cook your dish here

for _ in range(int(input())):
    
    n = int(input())
    
    a = sorted(map(int, input().split()))
    b = sorted(map(int, input().split()))
    c = sorted(a+b)
    
    cnt = 0
    prev = c[0]
    flag = True
    
    for i in range(2*n):
        if c[i] == prev:
            cnt += 1
        else:
            if cnt%2 == 0:
                cnt = 1
                prev = c[i]
            else:
                flag = False
                break
    
    if flag == False:
        print("-1")
        continue
    
    a1 = dict()
    b1 = dict()
    
    prev = a[0]
    a1[str(a[0])] = 1
    b1[str(a[0])] = 0
    
    for i in range(1, n):
        if prev == a[i]:
            a1[str(prev)] += 1
        else:
            prev = a[i]
            a1[str(prev)] = 1
            b1[str(prev)] = 0
    
    prev = b[0]
    b1[str(b[0])] = 1
    if not(str(prev) in a1):
        a1[str(prev)] = 0
        
    for i in range(1, n):
        if prev == b[i]:
            b1[str(prev)] += 1
        else:
            prev = b[i]
            b1[str(prev)] = 1
            if not(str(prev) in a1):
                a1[str(prev)] = 0
    
    c1 = dict()
    cnt1 = 0
    
    for key in a1:
        c1[key] = abs((a1[key] - b1[key]) / 2)
        cnt1 += int(c1[key])
        
    assert cnt1 % 2 == 0
    
    # print(a1)
    # print(b1)
    # print(c1)
    # print(cnt1)
    
    i = 0
    cost = 0
    mini = c[0]
    # print(mini)
    
    key = str(mini)
    
    if c1[key] != 0:
        cost += mini*int(c1[key])
        i += int(c1[key])
        c1[key] = 0
    
    
    for keys in sorted(list(map(int, c1.keys()))):
        if i >= cnt1/2:
            break
        key = str(keys)
        if c1[key] != 0:
            if mini*2 > int(key):
                cost += int(key) * int(c1[key])
                i += int(c1[key])
            else:
                cost += 2 * mini * int(c1[key])
                i += int(c1[key])
            
            if i >= cnt1/2:
                break
    
    print(cost)      
    