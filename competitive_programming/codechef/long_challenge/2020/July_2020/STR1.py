# cook your dish here
for _ in range(int(input())):
    n = int(input())
    strs = list(input().split())
    
    skip = 0
    
    for i in range(n-1):
        skip += abs(int(strs[i+1]) - int(strs[i])) - 1
        
    print(skip)
    