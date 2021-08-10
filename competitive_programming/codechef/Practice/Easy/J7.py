# cook your dish here

for i in range(int(input())):
    
    p, s = map(int, input().split())
    
    a = (p / 12.0) - ((p*p - 24*s)**0.5)/12.0
    
    v = a * (s/2.0 - a*(p/4.0 - a))
    
    print(round(v, 2))

