# cook your dish here
import math
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    maxi = max(a)
    
    p = 0
    summ = 0
    while pow(2,p-1) <= maxi:
        power = pow(2, p)
        cnt = 0
        for x in a:
            if x % power >= power/2:
                cnt += 1
        summ += math.ceil(cnt/k)
        p += 1
    print(summ)
 
