# cook your dish here
def digitsum(x):
    ds = 0
    
    while(x > 0):
        ds += x % 10
        x = x // 10
    
    return ds

for _ in range(int(input())):
    n = int(input())
    
    sa, sb = 0, 0
    for _ in range(n):
        a,b = map(int, input().split())
    
        if digitsum(a) > digitsum(b):
            sa += 1
        elif digitsum(b) > digitsum(a):
            sb += 1
        else:
            sa += 1
            sb += 1
    
    if sa > sb:
        print(0, sa)
    elif sb > sa:
        print(1, sb)
    else:
        print(2, sa)