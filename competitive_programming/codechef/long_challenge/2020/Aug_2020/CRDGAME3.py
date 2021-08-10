# cook your dish here
import math
for _ in range(int(input())):
    c,r = map(int, input().split())
    
    c,r = math.ceil(c/9), math.ceil(r/9)
    
    if c < r:
        print("0 " + str(c))
    else:
        print("1 " + str(r))