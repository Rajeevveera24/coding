# cook your dish here

import sys

n = int(input())

min1, max1 = 1, n

min2, max2 = 1, n

y1,y2 = (max1 +  min1) // 2, (max2 + min2) // 2

for i in range(300):
    if i % 2 == 0:
        print(y1, flush = True)
        ans = input()
        if ans == "G":
            min1 = y1
            y1 = (max1 + min1) // 2
        elif ans == "L":
            max1 = y1
            y1 = (max1 + min1) // 2
        else:
            exit(0)
    
    else:
        print(y2, flush = True)
        ans = input()
        if ans == "G":
            min2 = y2
            y2 = (max2 + min2) // 2
        elif ans == "L":
            max2 = y2
            y2 = (max2 + min2) // 2
        else:
            exit(0)
                    