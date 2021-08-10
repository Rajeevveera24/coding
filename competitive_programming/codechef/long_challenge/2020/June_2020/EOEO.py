# cook your dish here
for t in range(int(input())):
    
    ts = int(input())
    temp = ts
    cnt = 0
    
    while(ts % 2 == 0):
        ts /= 2
        cnt += 1
    
    js = int((temp) // (2**(cnt+1)))
    
    print(js)
        


# from math import ceil, floor, pow

# T = float(input())
    
# while (T > 0) :
    
#     ts = float(input())
#     temp = float(ts)
    
#     cnt = 1
    
#     if ts % 2 == 1:
#         print(int(ts//2))
#         T -= 1
#         continue
    
#     while ts % int(pow(2, cnt)) == 0:
#         cnt += 1
        
#     print(int(temp // pow(2, cnt)))
    
#     T = T - 1
    
#     # print(T)