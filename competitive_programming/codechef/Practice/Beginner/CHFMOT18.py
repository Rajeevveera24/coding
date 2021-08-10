# cook your dish here
for _ in range(int(input())):
    
    s, n = map(int, input().split())
    
    assert n % 2 == 0
    
    if s % 2 == 0 and s <= n:
        print(1)
    elif s%2 != 0 and s <= n:
        if s == 1:
            print(1)
        else:
            print(2)
    elif s % 2 == 0 and s > n:
        if s % n == 0:
            print(s//n)
        else:
            print(s//n + 1)
    else:
        if (s%n) == 1:
            print(s//n + 1)
        else:
            print(s//n + 1 + 1)
        
        