# cook your dish here
for _ in range(int(input())):
    d, x, y, z = map(int, input().split())
    print(max(x*7, d*y + (7-d)*z))
  
