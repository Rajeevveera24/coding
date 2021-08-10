# cook your dish here
for _ in range(int(input())):
    h,p = map(int, input().split())
    assert p >= 1 and p <= 10**5 and h >= 1 and h <= 10**6
    if h <= p:
        print(1)
        continue
    while h > 0:
        h -= p
        if h <= 0:
            print(1)
            break
        p = p//2
        if p == 0:
            print(0)
            break
    
    
        